package ddwu.mobile.finalproject

import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import ddwu.mobile.finalproject.data.Diary
import ddwu.mobile.finalproject.databinding.ItemDiaryBinding

class DiaryAdapter(var diaries: List<Diary>, val onLongClick: (Diary) -> Unit)
    : RecyclerView.Adapter<DiaryAdapter.DiaryViewHolder>() {

    override fun getItemCount(): Int = diaries.size

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): DiaryViewHolder {
        val foodBinding = ItemDiaryBinding.inflate(
            LayoutInflater.from(parent.context),
            parent,
            false
        )
        return DiaryViewHolder(foodBinding)
    }

    override fun onBindViewHolder(holder: DiaryViewHolder, position: Int) {
        val diary = diaries[position]
        holder.diaryBinding.tvItemId.text = diary._id.toString()
        holder.diaryBinding.tvItemEmotion.text = when (diary.emotion) {
            "happy" -> "\uD83D\uDE0A"
            "neutral" -> "\uD83D\uDE10"
            "sad" -> "\uD83D\uDE22"
            "angry" -> "\uD83D\uDE20"
            else -> "\uD83D\uDE10"
        }
        holder.diaryBinding.tvItemDate.text = diary.date
        holder.diaryBinding.tvItemTitle.text = diary.title

        holder.diaryBinding.root.setOnClickListener {
            val intent = android.content.Intent(holder.itemView.context, AddDiaryActivity::class.java)
            intent.putExtra("diary_data", diary)
            holder.itemView.context.startActivity(intent)
        }

        holder.diaryBinding.root.setOnLongClickListener {
            onLongClick(diary)
            true
        }
    }

    class DiaryViewHolder(val diaryBinding: ItemDiaryBinding)
        : RecyclerView.ViewHolder(diaryBinding.root)
}