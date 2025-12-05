<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>웹프로그래밍 기말 과제</title>
<style>
.cal {
	width: 80%;
	margin:auto;
	border-collapse: collapse;
	border: 1px solid black;
}
td, th {
	width: 10%;
	border-collapse: collapse;
	border: 1px solid grey;
	padding: 5px;
}
.sat {
	color: blue;
}
.sun {
	color: red;
}
</style>
</head>
<body>

<%!
String[] week = new String[] { "", "일", "월", "화", "수", "목", "금", "토" };

Calendar today = Calendar.getInstance();		// [today] 변하지 않는 오늘 날짜 (변경 금지)
Calendar viewDate = Calendar.getInstance();		// [viewDate] 지금 보고 있는 날짜
Calendar calcCal = (Calendar) viewDate.clone();	// [calcCal] 지금 보고 있는 날짜의 1일 (달력 표시용)
// 2025년 5!, 6!, 8, 9월로 테스트 해보기

// 오늘 날짜 정보 (today)
int tY = today.get(Calendar.YEAR);
int tM = today.get(Calendar.MONTH) + 1;	// 1월(JANUARY) = 0, 2월 = 1, ..., 12월(DECEMBER) = 11
int tD = today.get(Calendar.DATE);
// 현재 다루는 날짜 정보 (viewDate)
int year, month, date;
// 실제 나타낼 달력의 정보 (calcCal)
int dayOfWeek, firstDate, lastDate, startDayOfWeek;
// 달력 문자열로 처리할 때
String yearMonth = String.format("%02d-%02d", year, month);
%>

<%
//전달받은 날짜 정보
String sY = request.getParameter("YEAR");
String sM = request.getParameter("MONTH");

// 전달받은 날짜 정보가 없으면 오늘 날짜를 기준으로
if (sY == null || sM == null) {
	year = tY;
	month = tM;
	date = tD;
}
else {
	year = Integer.parseInt(sY);
	month = Integer.parseInt(sM);
	date = tD;
}

// 달력 날짜 설정
viewDate.set(year, month - 1, date);
calcCal.set(year, month - 1, 1);

dayOfWeek = calcCal.get(Calendar.DAY_OF_WEEK);	// SUNDAY = 1, MONDAY = 2, ..., SATURDAY = 7
firstDate = calcCal.getMinimum(Calendar.DATE);
lastDate = calcCal.getActualMaximum(Calendar.DAY_OF_MONTH);
startDayOfWeek = calcCal.get(Calendar.DAY_OF_WEEK);

int count = 0;	// 7일마다 줄 바꿔주는 용
int day = 0;	// 달력에 날짜 쓰는 용

// session에 diary map 저장
HashMap<String, String> dmap = (HashMap<String, String>)session.getAttribute("diary");
if (dmap == null) {
    dmap = new HashMap<String, String>();
    session.setAttribute("diary", dmap);
}
%>

<table style="width: 100%;">
<tr>
	<td style="border:none; text-align:left;">
		<a href="Calendar.jsp?YEAR=<%=year-1 %>&MONTH=<%=month %>">◀</a>
		<%=year %>년
		<a href="Calendar.jsp?YEAR=<%=year+1 %>&MONTH=<%=month %>">▶</a>
	</td>
	<td style="border:none; text-align:center;">
		<%
		if (month <= 1)
			out.println("◀");
		else
			out.println("<a href='Calendar.jsp?YEAR=" + year + "&MONTH=" + (month-1) + "'>◀</a>");
		%>
		
		<%=month %>월
		
		<%
		if (month >= 12)
			out.println("▶");
		else
			out.println("<a href='Calendar.jsp?YEAR=" + year + "&MONTH=" + (month+1) + "'>▶</a>");
		%>
	</td>
	<td style="border:none; text-align:right;">
		<%=tY %>-<%=tM %>-<%=String.format("%02d", tD) %>
	</td>
</tr>
</table>

<table class="cal">
<%
// 요일 출력
out.println("<tr>");
out.println("<th class='sun'>일</th>");
for (int i = 2; i < 7; i++) {
	out.println("<th>" + week[i] + "</th>");
}
out.println("<th class='sat'>토</th>");
out.println("</tr>");
// 첫 번째 주 빈칸
out.println("<tr>");
for (count = 1; count < startDayOfWeek; count++) {
	out.println("<td>&nbsp;</td>");
}
// 날짜
for (day = 1; day <= lastDate; day++, count++) {
	String diary = String.format("%d<br>", day);
	String task = dmap.get(String.format("%d-%02d-%02d", year, month, day));
	if (task != null)
		diary += task;
	else
		diary += "&nbsp;";
	
	if (count % 7 == 1) {
		out.println("<tr>");
		out.println("<td class='sun'>" + diary + "</td>");
	}
	else if (count % 7 == 0) {
		out.println("<td class='sat'>" + diary + "</td>");		
		out.println("</tr>");
	}
	else {
		out.println("<td>" + diary + "</td>");
	}
}
// 마지막 주 빈칸
while (count++ % 7 != 1) {
	out.println("<td>&nbsp;</td>");
}
%>
</table>

<hr>

<div style="text-align:center; margin:10px">
<form name="diary" action="Add.jsp" method="post">
날짜: <input type="date" name="date" style="margin-right: 15px;" />
일정: <input type="text" name="task" size="70" />
<input type="submit" value="일정 등록" />
</form>
</div>

<%
for (String target: dmap.keySet()) {
	String task = dmap.get(target);
	if (target.indexOf(yearMonth) >= 0) {
		out.println("<li>" + target + " : " + task + "</li>");
	}
}
%>
</ul>

</body>
</html>