package ddwu.mobile.finalproject.data

import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.OnConflictStrategy
import androidx.room.Query
import androidx.room.Update
import kotlinx.coroutines.flow.Flow

@Dao
interface DiaryDao {
    @Insert(onConflict = OnConflictStrategy.REPLACE)
    suspend fun insertDiary(diary: Diary)

    @Update
    suspend fun updateDiary(diary: Diary) : Int

    @Delete
    suspend fun deleteDiary(diary: Diary)

    @Query("SELECT * FROM diary_table ORDER BY date DESC")
    fun getAllDiaries() : Flow<List<Diary>>

    @Query("SELECT* FROM diary_table WHERE _id = :id")
    suspend fun getDiaryById(id: Long): Diary?

    @Query("SELECT * FROM diary_table WHERE date = :date")
    suspend fun getDiaryByDate(date: String) : List<Diary>
}