package jspbook.w16;

import java.util.Objects;

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
	
	@Override
	public int hashCode() {
	    // 년, 월, 일이 같으면 같은 해시코드를 반환
	    return Objects.hash(year, month, day);
	}
	
	@Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        
        Date other = (Date) obj;
        if (day != other.day)
            return false;
        if (month != other.month)
            return false;
        if (year != other.year)
            return false;
        
        return true;
    }
}