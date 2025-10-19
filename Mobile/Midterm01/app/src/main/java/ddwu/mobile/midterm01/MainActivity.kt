package ddwu.mobile.midterm01

import android.os.Bundle
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.room.Room
import ddwu.mobile.midterm01.data.FoodDao
import ddwu.mobile.midterm01.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    lateinit var binding: ActivityMainBinding
    lateinit var foodDao: FoodDao

    override fun onCreate(savedInstanceState: Bundle?) {
        binding = ActivityMainBinding.inflate(layoutInflater)
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val foodDB: FoodDB = Room.databaseBuilder(
            applicationContext, FoodDB::class.java, "food_db"
        ).build()

        foodDao = foodDB.foodDao()

        binding.btnSelect.setOnClickListener {
            val foods = foodDao.getAllFoods()
            binding.tvInfo.setText(foods.toString())
        }
    }
}