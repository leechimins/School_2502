package jspbook.w16;

import java.util.*;

public class Scheduler {
	private HashMap<Date, String> diary = new HashMap<Date, String>();
	
	public void add(Date date, String task) {
		this.diary.put(date, task);
	}
	
	public ArrayList<String> scheduleOfMonth(int year, int month) {
		ArrayList<String> schedule = new ArrayList<String>();
		schedule.add("0일은 없습니다.");
		
		Calendar calcCal = Calendar.getInstance();
		calcCal.set(year, month - 1, 1);
		int lastDate = calcCal.getActualMaximum(Calendar.DAY_OF_MONTH);
		
		// 임시값으로 객체 생성
		Date myDate = Date.getInstance("2000-01-01");

		for (int day = 1; day <= lastDate; day++) {
			myDate.setDate(String.format("%d-%02d-%02d", year, month, day));
			String task = this.diary.get(myDate);
			if (task == null)
				task = "&nbsp";
			schedule.add(task);
		}
		
		return schedule;
	}
}
