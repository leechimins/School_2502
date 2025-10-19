package ddwu.mobile.midterm01.data

import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.Query
import androidx.room.Update

@Dao
interface FoodDao {
    @Insert
    fun insertFood(vararg food: Food)

    @Update
    fun updateFood(food: Food)

    @Delete
    fun deleteFood(food: Food)

    @Query("SELECT * FROM food_table")
    fun getAllFoods() : List<Food>

    @Query("SELECT * FROM food_table WHERE _id = :id")
    fun getFood(id: Int) : Food

    @Query("SELECT * FROM food_table WHERE food_name IN (:names)")
    fun getFoodsByName(names: List<String>) : List<Food>

    @Query("DELETE FROM food_table WHERE _id = :id")
    fun deleteFoodById(id: Int)

    @Query("DELETE FROM food_table WHERE _id = :id")
    fun hello(id: Int)
}