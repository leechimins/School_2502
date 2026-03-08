package ddwu.mobile.finalproject

import android.Manifest
import android.Manifest.permission.ACCESS_COARSE_LOCATION
import android.Manifest.permission.ACCESS_FINE_LOCATION
import android.content.Intent
import android.content.pm.PackageManager
import android.location.Geocoder
import android.net.Uri
import android.os.Bundle
import android.os.Looper
import android.provider.MediaStore
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.FileProvider
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.bumptech.glide.Glide
import com.google.android.gms.location.FusedLocationProviderClient
import com.google.android.gms.location.LocationCallback
import com.google.android.gms.location.LocationRequest
import com.google.android.gms.location.LocationResult
import com.google.android.gms.location.LocationServices
import com.google.android.gms.location.Priority
import ddwu.mobile.finalproject.data.Diary
import ddwu.mobile.finalproject.data.DiaryDB
import ddwu.mobile.finalproject.databinding.ActivityAddDiaryBinding
import ddwu.mobile.finalproject.file.FileUtil
import ddwu.mobile.finalproject.network.QuoteService
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import java.io.File
import java.io.IOException
import java.text.SimpleDateFormat
import java.util.Date
import java.util.Locale

class AddDiaryActivity : AppCompatActivity() {

    private val binding by lazy { ActivityAddDiaryBinding.inflate(layoutInflater) }
    private val diaryDao by lazy { DiaryDB.getDB(this).diaryDao() }
    private var updateDiary: Diary? = null
    private lateinit var quoteService: QuoteService
    private lateinit var fusedLocClient: FusedLocationProviderClient
    private lateinit var locRequest: LocationRequest
    private lateinit var locCallback: LocationCallback
    private val geocoder: Geocoder by lazy { Geocoder(this, Locale.getDefault()) }
    private var currPhotoPath: String? = null
    private var currPhotoUri: Uri? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        /* 위치 초기 설정 */
        fusedLocClient = LocationServices.getFusedLocationProviderClient(this)
        locRequest = LocationRequest.Builder(5000)
            .setMinUpdateIntervalMillis(3000)
            .setPriority(Priority.PRIORITY_BALANCED_POWER_ACCURACY)
            .build()

        /* 일기 수정 시 넣을 정보 */
        updateDiary = intent.getSerializableExtra("diary_data") as? Diary
        if (updateDiary != null) {
            binding.tvDateDisplay.text = updateDiary!!.date
            binding.etTitle.setText(updateDiary!!.title)
            binding.etContent.setText(updateDiary!!.content)
            binding.tvQuoteContent.text = updateDiary!!.quote

            when (updateDiary!!.emotion) {
                "happy" -> binding.rbHappy.isChecked = true
                "neutral" -> binding.rbNeutral.isChecked = true
                "sad" -> binding.rbSad.isChecked = true
                "angry" -> binding.rbAngry.isChecked = true
            }
            val loc = geocoder.getFromLocation(updateDiary!!.latitude, updateDiary!!.longitude, 1) {
                addresses ->
                CoroutineScope(Dispatchers.Main).launch {
                    binding.etLocation.setText("${addresses[0].getAddressLine(0)}")
                }
            }
            binding.etLocation.setText("${updateDiary!!.latitude},${updateDiary!!.longitude}")

            currPhotoPath = updateDiary!!.imgPath
            if (currPhotoPath != null) {
                val file = File(currPhotoPath!!)
                if (file.exists()) {
                    Glide.with(this).load(file).into(binding.ivPhoto)
                    binding.ivPhoto.visibility = View.VISIBLE
                    binding.layoutAddPhoto.visibility = View.GONE
                }
            }
        }

        else {
            // 현재 날짜 자동으로 가져오기
            val currentDate: String = SimpleDateFormat("yyyy.MM.dd", Locale.KOREA).format(Date())
            binding.tvDateDisplay.text = currentDate
        }

        /* Retrofit 시작 */
        val retrofit = Retrofit.Builder()
            .baseUrl("http://api.quotable.io/")
            .addConverterFactory(GsonConverterFactory.create())
            .build()
        quoteService = retrofit.create(QuoteService::class.java)

        /* 감정 버튼 클릭 -> API 호출 */
        binding.rbHappy.setOnClickListener {
            fetchQuote("happiness")
        }
        binding.rbAngry.setOnClickListener {
            fetchQuote("wisdom")
        }
        binding.rbSad.setOnClickListener {
            fetchQuote("success")
        }
        binding.rbNeutral.setOnClickListener {
            fetchQuote("famous-quotes")
        }

        binding.layoutAddPhoto.setOnClickListener {
            val options = arrayOf("사진 촬영", "갤러리에서 선택")

            AlertDialog.Builder(this)
                .setTitle("사진 추가")
                .setItems(options) { _, which ->
                    when (which) {
                        0 -> dispatchTakePictureIntent()
                        1 -> openGallery()
                    }
                }
                .show()
        }

        binding.btnSearchLocation.setOnClickListener {
            geocoder.getFromLocationName(binding.etLocation.text.toString(), 1) {
                addresses ->
                val lat = addresses[0].latitude
                val lng = addresses[0].longitude
                CoroutineScope(Dispatchers.Main).launch {
                    binding.etLocation.setText("$lat,$lng")
                }
            }
        }

        /* 저장 버튼을 누른 경우 -> 위치 정보 획득 */
        binding.btnSave.setOnClickListener {
            if (binding.etTitle.text.isBlank() || binding.etContent.text.isBlank()) {
                Toast.makeText(this, "제목과 내용을 모두 입력해주세요.", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            val locStr = binding.etLocation.text.toString()
            val latlngParts = locStr.trim().split(",")

            if (locStr.isBlank()) {
                if (checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
                    locCallback = object : LocationCallback() {
                        override fun onLocationResult(p0: LocationResult) {
                            val location = p0.locations[0]
                            fusedLocClient.removeLocationUpdates(this)
                            Toast.makeText(this@AddDiaryActivity, "현재 위치를 확인 중입니다...", Toast.LENGTH_SHORT).show()
                            saveDiary(location.latitude, location.longitude)
                        }
                    }
                    fusedLocClient.requestLocationUpdates(
                        locRequest,
                        locCallback,
                        Looper.getMainLooper()
                    )
                } else {
                    checkPermissions()
                }
            } else if (latlngParts.size == 2 && latlngParts[0].toDoubleOrNull() != null) {
                saveDiary(latlngParts[0].toDouble(), latlngParts[1].toDouble())
            } else {
                Toast.makeText(this, "장소 검색 버튼을 눌러주세요.", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }
        }

        // 취소 버튼을 누른 경우
        binding.btnCancel.setOnClickListener {
            Toast.makeText(this, "기록을 취소했습니다.", Toast.LENGTH_SHORT).show()
            finish()
        }
    }

    private fun fetchQuote(tagName: String) {
        CoroutineScope(Dispatchers.Main).launch {
            val response = quoteService.getRandomQuote(tagName)
            if (response.isNotEmpty()) {
                binding.tvQuoteContent.text = response[0].content
            } else {
                binding.tvQuoteContent.text = "오늘 하루도 수고 많으셨어요."
            }
        }
    }

    private fun getEmotion(): String {
        return when (binding.rgEmotion.checkedRadioButtonId) {
            R.id.rbHappy -> "happy"
            R.id.rbNeutral -> "neutral"
            R.id.rbSad -> "sad"
            R.id.rbAngry -> "angry"
            else -> "neutral"
        }
    }

    private fun saveDiary(lat: Double, lng: Double) {
        if (updateDiary != null) {
            val newDiary = Diary(
                updateDiary!!._id,
                binding.tvDateDisplay.text.toString(),
                getEmotion(),
                binding.etTitle.text.toString(),
                binding.etContent.text.toString(),
                lat,
                lng,
                currPhotoPath,
                binding.tvQuoteContent.text.toString()
            )

            CoroutineScope(Dispatchers.IO).launch {
                diaryDao.updateDiary(newDiary)
                launch(Dispatchers.Main) {
                    Toast.makeText(this@AddDiaryActivity, "일기가 수정되었습니다.", Toast.LENGTH_SHORT).show()
                    finish()
                }
            }
        } else {
            val newDiary = Diary(
                0,
                binding.tvDateDisplay.text.toString(),
                getEmotion(),
                binding.etTitle.text.toString(),
                binding.etContent.text.toString(),
                lat,
                lng,
                currPhotoPath,
                binding.tvQuoteContent.text.toString()
            )

            CoroutineScope(Dispatchers.IO).launch {
                diaryDao.insertDiary(newDiary)
                launch(Dispatchers.Main) {
                    Toast.makeText(this@AddDiaryActivity, "일기가 기록되었습니다.", Toast.LENGTH_SHORT).show()
                    finish()
                }
            }
        }
    }

    /* 위치 정보 권한 처리 */
    private fun checkPermissions() {
        if (checkSelfPermission(ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
            && checkSelfPermission(ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            Log.d("LBS", "필요 권한 있음")
        } else {
            locationPermissionRequest.launch(
                arrayOf(ACCESS_FINE_LOCATION, ACCESS_COARSE_LOCATION)
            )
        }
    }

    val locationPermissionRequest =
        registerForActivityResult( ActivityResultContracts.RequestMultiplePermissions(), {
            permissions ->
            when {
                permissions.getOrDefault(ACCESS_FINE_LOCATION, false) -> {
                    Log.d("LBS", "정확한 위치 사용")
                }
                permissions.getOrDefault(ACCESS_COARSE_LOCATION, false) -> {
                    Log.d("LBS", "근사 위치 사용")
                }
                else -> {
                    Log.d("LBS", "권한 미승인")
                }
            }
        } )


    /* 사진 */
    private val takePictureLauncher = registerForActivityResult(
        ActivityResultContracts.StartActivityForResult() ) {
        result ->
        if (result.resultCode == RESULT_OK) {
            displayImage(currPhotoUri!!)
        } else {
            Toast.makeText(this, "사진 촬영 취소", Toast.LENGTH_SHORT).show()
            removeCurrentImage()
        }
    }

    private val galleryLauncher = registerForActivityResult(
        ActivityResultContracts.GetContent() ) { uri: Uri? ->
        displayImage(uri!!)
    }

    private fun openGallery() {
        galleryLauncher.launch("image/*")
    }

    private fun dispatchTakePictureIntent() {
        val takePictureIntent = Intent(MediaStore.ACTION_IMAGE_CAPTURE)

        if (takePictureIntent.resolveActivity(packageManager) != null) {
            val photoFile: File? = try {
                val file = FileUtil.createNewFile(this)
                currPhotoPath = file.absolutePath
                file
            } catch (ex: IOException) {
                null
            }

            photoFile?.also {
                val photoURI: Uri = FileProvider.getUriForFile(
                    this,
                    "${application.packageName}.fileprovider",
                    it
                )
                currPhotoUri = photoURI
                takePictureIntent.putExtra(MediaStore.EXTRA_OUTPUT, photoURI)
                takePictureLauncher.launch(takePictureIntent)
            }
        } else {
            Log.e("Photo", "카매라 앱 미확인")
        }
    }

    private fun displayImage(uri: Uri) {
        if (uri != null) {
            Glide.with(this).load(uri).into(binding.ivPhoto)
            currPhotoUri = uri
            currPhotoPath = FileUtil.saveFileToExtStorage(this, currPhotoUri)
            binding.ivPhoto.visibility = View.VISIBLE
            binding.layoutAddPhoto.visibility = View.GONE
            Toast.makeText(this, "사진을 가져왔습니다.", Toast.LENGTH_SHORT).show()
        } else {
            Toast.makeText(this, "사진 촬영 취소", Toast.LENGTH_SHORT).show()
        }
    }

    private fun removeCurrentImage() {
        try {
            val isRemoved = FileUtil.deleteFile(currPhotoPath)
            if (isRemoved) {
                Glide.with(this)       // 기본 사진으로 변경
                    .load(android.R.drawable.ic_menu_camera)  // Android 기본 icon 사용
                    .into(binding.ivPhoto)
                currPhotoUri = null
                currPhotoPath = null
            }
        } catch (e: IOException) {
            Log.e("Photo", "이미지 삭제 오류", e)
        }
    }
}