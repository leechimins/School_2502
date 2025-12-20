package ddwu.mobile.finalproject

import android.os.Bundle
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import ddwu.mobile.finalproject.data.Diary
import ddwu.mobile.finalproject.data.DiaryDB
import ddwu.mobile.finalproject.databinding.ActivityAddDiaryBinding
import ddwu.mobile.finalproject.databinding.ActivityMainBinding
import kotlinx.coroutines.launch
import java.text.SimpleDateFormat
import java.util.Date
import java.util.Locale

class AddDiaryActivity : AppCompatActivity() {

    private val binding by lazy { ActivityAddDiaryBinding.inflate(layoutInflater) }
    private val diaryDao by lazy { DiaryDB.getDB(this).diaryDao() }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val currentDate = SimpleDateFormat("yyyy.MM.dd", Locale.KOREA).format(Date())
        binding.tvDateDisplay.text = currentDate

        binding.btnSave.setOnClickListener {
            val title = binding.etTitle.text.toString()
            val content = binding.etContent.text.toString()
            val emotion = getEmotion()

            if (title.isBlank() || content.isBlank()) {
                Toast.makeText(this, "제목과 내용을 모두 입력해주세요.", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            val newDiary = Diary(
                0, currentDate, emotion, title, content,
                0.0, 0.0,
                null
            )

            lifecycleScope.launch {
                diaryDao.insertDiary(newDiary)
                finish()
            }
        }

        binding.btnCancel.setOnClickListener {
            finish()
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
}