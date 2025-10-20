package ddwu.mobile.midterm01

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import ddwu.mobile.midterm01.data.Food
import ddwu.mobile.midterm01.data.FoodDao
import kotlin.concurrent.Volatile

@Database([Food::class], version = 1)
abstract class FoodDB : RoomDatabase() {
    abstract fun foodDao() : FoodDao

    companion object {
        @Volatile private var INSTANCE: FoodDB? = null

        fun getDB(context: Context) : FoodDB {
            return INSTANCE ?: synchronized(this) {
                val instance = Room.databaseBuilder(
                    context.applicationContext, FoodDB::class.java, "food_db"
                ).build()
                INSTANCE = instance
                instance
            }
        }
    }
}