package ddwu.mobile.midterm01.data

import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.Query
import androidx.room.Update
import kotlinx.coroutines.flow.Flow

@Dao
interface FoodDao {
    @Insert
    suspend fun insertFood(vararg food: Food)

    @Update
    suspend fun updateFood(food: Food)

    @Delete
    suspend fun deleteFood(food: Food)

    @Query("SELECT * FROM food_table")
    fun getAllFoods() : Flow<List<Food>>

    @Query("SELECT * FROM food_table WHERE _id = :id")
    suspend fun getFood(id: Int) : Food

    @Query("SELECT * FROM food_table WHERE food_name IN (:names)")
    suspend fun getFoodsByName(names: List<String>) : List<Food>

    @Query("DELETE FROM food_table WHERE _id = :id")
    suspend fun deleteFoodById(id: Int)

    @Query("UPDATE food_table SET food_price = :price WHERE food_name = :name")
    suspend fun updateFoodByName(name: String, price: Int)
}