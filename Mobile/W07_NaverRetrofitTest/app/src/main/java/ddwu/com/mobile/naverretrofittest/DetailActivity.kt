package ddwu.com.mobile.naverretrofittest

import android.graphics.Bitmap
import android.graphics.drawable.Drawable
import android.os.Bundle
import android.util.Log
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.bumptech.glide.Glide
import com.bumptech.glide.request.target.CustomTarget
import com.bumptech.glide.request.transition.Transition
import ddwu.com.mobile.naverretrofittest.data.Book
import ddwu.com.mobile.naverretrofittest.databinding.ActivityDetailBinding
import java.io.File
import java.io.FileOutputStream
import java.text.SimpleDateFormat
import java.util.Date

class DetailActivity : AppCompatActivity() {
    lateinit var binding: ActivityDetailBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        binding = ActivityDetailBinding.inflate(layoutInflater)
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val data = intent.getSerializableExtra("book") as Book
        val fileName = getCurrentTime()

        Glide.with(this)
            .load(data.image)
            .into(binding.imageView2)

        binding.btnSave.setOnClickListener {
            Glide.with(this)
                .asBitmap()
                .load(data.image)
                .into(object: CustomTarget<Bitmap>(300, 300) {
                    override fun onResourceReady(
                        resource: Bitmap,
                        transition: Transition<in Bitmap>?,
                    ) {
                        val subDir = File(filesDir, "images")
                        if (!subDir.exists()) {
                            subDir.mkdir()
                        }
                        val imageFile = File("${filesDir}/images", "${fileName}.jpg")
                        val fos = FileOutputStream(imageFile)
                        resource.compress(Bitmap.CompressFormat.JPEG, 100, fos)
                        fos.close()
                    }

                    override fun onLoadCleared(placeholder: Drawable?) {
                        Log.d("MOBILE", "image load cleared!!")
                    }
                })
        }

        binding.btnClose.setOnClickListener {
            val dir = File(filesDir, "images")
            dir.listFiles()?.forEach { file ->
                file.delete()
            }
            finish()
        }

    }

    fun getCurrentTime() = SimpleDateFormat("yyyyMMdd_HHmmss").format(Date())
}