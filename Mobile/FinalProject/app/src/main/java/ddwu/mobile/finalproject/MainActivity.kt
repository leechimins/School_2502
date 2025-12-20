package ddwu.mobile.finalproject

import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import androidx.recyclerview.widget.LinearLayoutManager
import ddwu.mobile.finalproject.data.Diary
import ddwu.mobile.finalproject.data.DiaryDB
import ddwu.mobile.finalproject.data.DiaryDao
import ddwu.mobile.finalproject.databinding.ActivityMainBinding
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.distinctUntilChanged
import kotlinx.coroutines.launch

class MainActivity : AppCompatActivity() {
    private val binding by lazy { ActivityMainBinding.inflate(layoutInflater) }
    private val diaryDB by lazy { DiaryDB.getDB(this) }
    private lateinit var diaryDao: DiaryDao
    private lateinit var adapter: DiaryAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        /* 일기 DB */
        diaryDao = diaryDB.diaryDao()

        /* RecyclerView 설정 */
        adapter = DiaryAdapter(ArrayList())
        val layoutManager = LinearLayoutManager(this)
        layoutManager.orientation = LinearLayoutManager.VERTICAL

        binding.rvDiaryList.layoutManager = layoutManager
        binding.rvDiaryList.adapter = adapter

        lifecycleScope.launch {
            diaryDao.getAllDiaries()
                .distinctUntilChanged()
                .collect { diaries ->
                    adapter.diaries = diaries
                    adapter.notifyDataSetChanged()
                }
        }

        binding.btnAdd.setOnClickListener {
            val intent = Intent(this, AddDiaryActivity::class.java)
            startActivity(intent)
        }


    }
}