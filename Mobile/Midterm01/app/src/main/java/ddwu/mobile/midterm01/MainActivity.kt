package ddwu.mobile.midterm01

import android.os.Bundle
import android.util.Log
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.room.Room
import ddwu.mobile.midterm01.data.Food
import ddwu.mobile.midterm01.data.FoodDao
import ddwu.mobile.midterm01.databinding.ActivityMainBinding
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.distinctUntilChanged
import kotlinx.coroutines.launch

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

        val foodDB = FoodDB.getDB(this)
        foodDao = foodDB.foodDao()

        binding.btnSelect.setOnClickListener {
            val foodsFlow: Flow<List<Food>> = foodDao.getAllFoods()
            CoroutineScope(Dispatchers.Main).launch {
                foodsFlow.distinctUntilChanged().collect { foods ->
                    var text = ""
                    for (food in foods) {
                        text += food.toString() + "\n"
                        Log.d("MAIN", food.toString())
                    }
                    binding.tvInfo.setText(text)
                }
            }
        }

        binding.btnInsert.setOnClickListener {
            CoroutineScope(Dispatchers.IO).launch {
                foodDao.insertFood(Food(0, "순두부", 13000))
            }
        }

        binding.btnUpdate.setOnClickListener {
            CoroutineScope(Dispatchers.IO).launch {
                foodDao.updateFoodByName("순두부", 9000)
            }.start()
        }

        binding.btnDelete.setOnClickListener {
            CoroutineScope(Dispatchers.IO).launch {
                foodDao.deleteFood(Food(1, "순두부", 13000))
            }.start()
        }
    }
}