package ddwu.mobile.finalproject.file

import android.content.Context
import android.net.Uri
import android.os.Environment
import android.util.Log
import java.io.File
import java.io.FileOutputStream
import java.io.IOException
import java.text.SimpleDateFormat
import java.util.Date

class FileUtil {
    companion object {
        private const val FILENAME_FORMAT = "yyyyMMdd_HHmmss"
        private fun getFileName(context: Context): String {
            val timeStamp: String = SimpleDateFormat(FILENAME_FORMAT).format(Date())
            val storageDir: File? = context.getExternalFilesDir(Environment.DIRECTORY_PICTURES)
            return "${storageDir?.path}/${timeStamp}.jpg"
        }

        @Throws(IOException::class)
        fun createNewFile(context: Context): File {
            val file = File(getFileName(context))
            return file
        }
        @Throws(IOException::class)
        fun deleteFile(filePath: String?) : Boolean {
            if (filePath.isNullOrEmpty()) return false
            val file = File(filePath)
            return if (file.exists()) {
                val deleted = file.delete()
                deleted
            } else {
                false
            }
        }

        fun saveFileToExtStorage(context: Context, sourceUri: Uri?) : String? {
            if (sourceUri == null) {
                return null
            }
            val saveTargetFile = File(getFileName(context))
            return try {
                context.contentResolver.openInputStream(sourceUri)?.use { input ->
                    FileOutputStream(saveTargetFile).use { output ->
                        input.copyTo(output)
                    }
                } ?: null
                saveTargetFile.absolutePath
            } catch (e: Exception) {
                Log.e("FileUtil", "파일 저장 오류: ${e.message}", e)
                return null
            }
        }
    }
}