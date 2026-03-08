package ddwu.mobile.finalproject.data

import com.google.gson.annotations.SerializedName

data class Quote(
    @SerializedName("content")
    val content: String,
    @SerializedName("author")
    val author: String
) {
    override fun toString(): String {
        return "$content ($author)"
    }
}
