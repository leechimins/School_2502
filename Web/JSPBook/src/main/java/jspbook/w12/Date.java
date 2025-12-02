package jspbook.w12;

public class Date {
	private Integer year;
	private Integer month;
	private Integer day;
	
	public Integer getYear() { return year; }
	public void setYear(Integer year) { this.year = year; }
	public Integer getMonth() { return month; }
	public void setMonth(Integer month) { this.month = month; }
	public Integer getDay() { return day; }
	public void setDay(Integer day) { this.day = day; }

	public void parseDate(String input) {
		String[] date = input.split("-");
		this.year = Integer.parseInt(date[0]);
		this.month = Integer.parseInt(date[1]);
		this.day = Integer.parseInt(date[2]);
	}
}