package ddwu.com.mobile.miniproject2

import android.Manifest.permission.ACCESS_COARSE_LOCATION
import android.Manifest.permission.ACCESS_FINE_LOCATION
import android.content.Intent
import android.content.pm.PackageManager
import android.location.Geocoder
import android.location.Location
import android.os.Bundle
import android.os.Looper
import android.util.Log
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.GeneratedAdapter
import com.google.android.gms.location.FusedLocationProviderClient
import com.google.android.gms.location.LocationCallback
import com.google.android.gms.location.LocationRequest
import com.google.android.gms.location.LocationResult
import com.google.android.gms.location.LocationServices
import com.google.android.gms.location.Priority
import com.google.android.gms.maps.CameraUpdateFactory
import com.google.android.gms.maps.GoogleMap
import com.google.android.gms.maps.OnMapReadyCallback
import com.google.android.gms.maps.SupportMapFragment
import com.google.android.gms.maps.model.BitmapDescriptorFactory
import com.google.android.gms.maps.model.LatLng
import com.google.android.gms.maps.model.Marker
import com.google.android.gms.maps.model.MarkerOptions
import ddwu.com.mobile.miniproject2.databinding.ActivityMainBinding
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.util.Locale
import kotlin.getValue

class MainActivity : AppCompatActivity() {

    val TAG = "MINI_PROJECT"
    val binding by lazy { ActivityMainBinding.inflate(layoutInflater) }
    lateinit var googleMap: GoogleMap
    lateinit var locClient: FusedLocationProviderClient
    lateinit var locRequest: LocationRequest
    lateinit var locCallBack: LocationCallback
    lateinit var currentLoc: Location
    var centerMarker: Marker? = null
    val geocoder: Geocoder by lazy { Geocoder(this, Locale.getDefault()) }


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        /*위치 확인 관련 코드 작성*/
        locClient = LocationServices.getFusedLocationProviderClient(this)

        locRequest = LocationRequest.Builder(5000)
            .setMinUpdateIntervalMillis(3000)
            .setPriority(Priority.PRIORITY_BALANCED_POWER_ACCURACY)
            .build()

        locCallBack = object : LocationCallback() {
            override fun onLocationResult(p0: LocationResult) {
                currentLoc = p0.locations[0]
                googleMap.animateCamera(
                    CameraUpdateFactory.newLatLngZoom(
                        LatLng(currentLoc.latitude, currentLoc.longitude), 17f)
                )
                centerMarker?.position = LatLng(currentLoc.latitude, currentLoc.longitude)
                locClient.removeLocationUpdates(this)
            }
        }

        /*구글 지도 객체 로딩 코드 작성*/
        val mapFragment = supportFragmentManager.findFragmentById(R.id.map) as SupportMapFragment
        mapFragment.getMapAsync(mapReadyCallback)
        
        // 현재 위치로 이동
        binding.btnCurrentLoc.setOnClickListener {
            locClient.requestLocationUpdates(
                locRequest, locCallBack, Looper.getMainLooper()
            )
        }

        binding.btnMoveLoc.setOnClickListener {
            geocoder.getFromLocationName(binding.etAddress.text.toString(), 1) {
                addresses ->
                currentLoc.latitude = addresses[0].latitude
                currentLoc.longitude = addresses[0].longitude
                CoroutineScope(Dispatchers.Main).launch {
                    googleMap.animateCamera(
                        CameraUpdateFactory.newLatLngZoom(
                            LatLng(currentLoc.latitude, currentLoc.longitude), 17f)
                    )
                    centerMarker?.position = LatLng(currentLoc.latitude, currentLoc.longitude)
                }
            }
        }

        binding.btnSaveLoc.setOnClickListener {
            val intent = Intent(this@MainActivity, LocationDetailActivity::class.java)

            /*Intent에 위도 경도 추가*/
            intent.putExtra("lat", currentLoc.latitude)
            intent.putExtra("lng", currentLoc.longitude)

            startActivity(intent)
        }


        binding.btnLocList.setOnClickListener {
            val intent = Intent(this@MainActivity, LocationsActivity::class.java)
            startActivity(intent)
        }


        /*마커 표시 함수 호출*/
        binding.btnShowMarkers.setOnClickListener {
            //readMarker()
        }

        binding.btnClearMarkers.setOnClickListener {
            // 모든 마커 삭제

            // 현재의 centerMarker 위치에 새롭게 centerMarker 추가
        }

        // 실행 시 위치서비스 관련 권한 확인
        checkPermissions()
    }


    /*Google Map 설정*/
    val mapReadyCallback = object : OnMapReadyCallback {
        override fun onMapReady(map: GoogleMap) {
            googleMap = map
            /*fragment 에 기록한 위치로  centerMarker 추가*/
            addCenterMarker(LatLng(37.606537,127.041758))

            /*최종 위치 확인 후 해당 위치로 지도 및 centerMarker 이동*/
            locClient.lastLocation.addOnSuccessListener { location ->
                googleMap.animateCamera(
                    CameraUpdateFactory.newLatLngZoom(
                        LatLng(location.latitude, location.longitude), 17f
                    )
                )
                centerMarker?.position = LatLng(location.latitude, location.longitude)
            }


        }
    }

    /*centerMarker를 추가하는 함수 구현*/
    private fun addCenterMarker(latLng: LatLng) {
        val markerOptions = MarkerOptions().apply {
            position(latLng)
            title("Title")
            snippet("description")
            icon(BitmapDescriptorFactory.fromResource(R.drawable.somsom))
        }
        centerMarker = googleMap.addMarker(markerOptions)
        centerMarker?.showInfoWindow()
        centerMarker?.tag = "DB_ID"
    }


    /*DB에 저장한 위치 정보를 사용하여 Marker 추가 함수 구현*/
    /*private fun readMarker() {
        if (googleMap != null) {
            CoroutineScope(Dispatchers.IO).launch {
                // DB의 정보로 Marker 추가 코드 구현


            }
        }
    }*/


    override fun onPause() {
        super.onPause()
        /*위치 정보 조사 중단 코드 추가*/
        locClient.removeLocationUpdates(locCallBack)
    }


    /*위치 정보 권한 처리*/
    private fun checkPermissions() {    // 권한 확인이 필요한 곳에서 호출
        if (checkSelfPermission(ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
            && checkSelfPermission(ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            Log.d(TAG, "필요 권한 있음")
            // 권한이 이미 있을 경우 필요한 기능 실행
        } else {
            // 권한이 없을 경우 권한 요청
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
                    Log.d(TAG, "정확한 위치 사용") // 정확한 위치 접근 권한 승인거부 후 해야할 작업
                }
                permissions.getOrDefault(ACCESS_COARSE_LOCATION, false) -> {
                    Log.d(TAG, "근사 위치 사용") // 근사 위치 접근 권한 승인 후 해야할 작업
                }
                else -> {
                    Log.d(TAG, "권한 미승인") // 권한 미승인 시 해야 할 작업
                }
            }
        } )
}