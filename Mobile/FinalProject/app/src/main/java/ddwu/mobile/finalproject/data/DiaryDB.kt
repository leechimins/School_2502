package ddwu.mobile.finalproject.data

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase

@Database([Diary::class], version = 1, exportSchema = false)
abstract class DiaryDB : RoomDatabase() {
    abstract fun diaryDao() : DiaryDao

    companion object {
        @Volatile private var INSTANCE: DiaryDB? = null

        fun getDB(context: Context) : DiaryDB {
            return INSTANCE ?: synchronized(this) {
                val instance = Room.databaseBuilder(
                    context.applicationContext,
                    DiaryDB::class.java,
                    "diary_db"
                ).build()
                INSTANCE = instance
                instance
            }
        }
    }
}