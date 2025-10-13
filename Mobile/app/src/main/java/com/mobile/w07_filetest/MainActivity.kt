package com.mobile.w07_filetest

import android.os.Bundle
import android.util.Log
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.mobile.w07_filetest.databinding.ActivityMainBinding
import java.io.BufferedReader
import java.io.File
import java.io.FileOutputStream
import java.io.FileReader

class MainActivity : AppCompatActivity() {
    lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        binding.btnCheckPath.setOnClickListener {
            var text = "내부 저장소 기본 파일 경로:\n${filesDir}\n\n"
            text += "내부 저장소 캐시 파일 경로:\n${cacheDir}\n\n"
            text += "외부 저장소 기본 파일 경로:\n${getExternalFilesDir(null)}\n\n"
            text += "외부 저장소 캐시 파일 경로:\n${externalCacheDir}\n\n"
            binding.textView.setText(text)
        }

        binding.btnWriteText.setOnClickListener {
            var writeText = "모바일 응용\n"
            val writeFile = File("${filesDir}/images", "output_text.txt")
            val outputStream = FileOutputStream(writeFile)
            outputStream.write(writeText.toByteArray())
            outputStream.close()

            writeText = "Mobile Application\n"
            openFileOutput("output_text.txt", MODE_APPEND).use {
                it.write(writeText.toByteArray())
            }
        }

        binding.btnReadText.setOnClickListener {
            val readFile = File("${filesDir}/images", "output_text.txt")
            val fileReader = FileReader(readFile)
            BufferedReader(fileReader).useLines { lines ->
                for (line in lines) {
                    Log.d("MOBILE", "파일 문자열: ${line}")
                }
            }

            openFileInput("output_text.txt").bufferedReader().useLines {
                lines ->
                lines.forEach { Log.d("MOBILE", "파일 문자열: ${it}") }
            }
        }

        binding.btnCreateSubDir.setOnClickListener {
            val subDir = File(filesDir, "images")
            if (!subDir.exists()){
                subDir.mkdir()
            }
        }

        binding.btnListNDel.setOnClickListener {
            var fileList = filesDir.listFiles()
            if (fileList != null) {
                for (file in fileList) {
                    Log.d("MOBILE", "파일 목록: ${file.name}")
                }
            }
            deleteFile("output_text.txt")
            // 폴더를 지우면?
        }

    }
}