package ddwu.mobile.midterm01

import androidx.room.Database
import androidx.room.RoomDatabase
import ddwu.mobile.midterm01.data.Food
import ddwu.mobile.midterm01.data.FoodDao

@Database([Food::class], version = 1)
abstract class FoodDB : RoomDatabase() {
    abstract fun foodDao() : FoodDao
}