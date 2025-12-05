package jspbook.w16;

public class Date {
	private int year;
	private int month;
	private int day;
	
	public int getYear() { return year; }
	public int getMonth() { return month; }
	public int getDay() { return day; }

	public void setDate(String formInput) {
		String[] ymd = formInput.split("-");
		this.year = Integer.parseInt(ymd[0]);
		this.month = Integer.parseInt(ymd[1]);
		this.day = Integer.parseInt(ymd[2]);
	}
	
	public static Date getInstance(String formInput) {
		Date myDate = new Date();
		myDate.setDate(formInput);
		return myDate;
	}
}