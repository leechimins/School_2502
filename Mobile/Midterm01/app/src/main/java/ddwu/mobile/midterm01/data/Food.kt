package ddwu.mobile.midterm01.data

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.Ignore
import androidx.room.PrimaryKey

@Entity ("food_table")
data class Food(
    @PrimaryKey(autoGenerate = true) val _id: Int,
    @ColumnInfo(name = "food_name") var food: String?,
    @ColumnInfo(name = "food_price") var price: Int?,
) {
    @Ignore var count: Int = 0
}