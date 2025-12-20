package ddwu.mobile.finalproject.data

import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity(tableName = "diary_table")
class Diary(
    @PrimaryKey(autoGenerate = true) val _id: Int = 0,
    val date: String,
    var emotion: String,
    var title: String,
    var content: String,
    var latitude: Double,
    var longitude: Double,
    var imgPath: String?,
    var quote: String = ""
) {
    override fun toString(): String = "[$_id] $title ($date)"
}