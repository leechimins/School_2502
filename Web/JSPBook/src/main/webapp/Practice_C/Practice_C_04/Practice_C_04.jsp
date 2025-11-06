<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.util.Calendar, java.util.Enumeration" %>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Calendar</title>
	<style>
	table {
		width: 100%;
		border-collapse: collapse;
		border: 1px solid grey;
	}
	td {
		border-collapse: collapse;
		border: 1px solid grey;
		text-align: center;
		height: 40px;
	}
	td.sat {
		color: blue;
	}
	td.sun {
		color: red;
	}
	</style>
</head>
<body>

<%!
Calendar cal;
String[] days = { "None", "일", "월", "화", "수", "목", "금", "토" };
int year, month, date;
int start, end, startDay, nowDate, count;
int displayYear, displayMonth, displayDate;
String sYear, sMonth;
%>

<%
cal = Calendar.getInstance();

// 보여질 오늘 날짜
displayYear = cal.get(Calendar.YEAR);
displayMonth = cal.get(Calendar.MONTH);
displayDate = cal.get(Calendar.DATE);

sYear = request.getParameter("YEAR");
sMonth = request.getParameter("MONTH");

if (sYear != null && sMonth != null) {
	// 전달된 날짜
	year = Integer.parseInt(sYear);
	month = Integer.parseInt(sMonth);
	date = displayDate;
}
else {
	// 오늘 날짜
	year = displayYear;
	month = displayMonth;
	date = displayDate;
}
cal.set(year, month, 1);

// 시작 요일, 시작 날짜, 끝 날짜
startDay = cal.get(Calendar.DAY_OF_WEEK);
start = cal.getMinimum(Calendar.DATE);
end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);

count = 0;
nowDate = start;
%>

<table style="border:none;">
<tr>
	<td style="border:none; text-align:left;">
		<a href="Practice_C_04.jsp?YEAR=<%=year-1 %>&MONTH=<%=month %>">◀</a>
		<%=year %>년
		<a href="Practice_C_04.jsp?YEAR=<%=year+1 %>&MONTH=<%=month %>">▶</a>
	</td>
	<td style="border:none;">
		<%
		if (month <= 1)
			out.println("<a>◀</a>");
		else
			out.println("<a href='Practice_C_04.jsp?YEAR=" + year + "&MONTH=" + (month-1) + "'>◀</a>");
		%>
		<%=month + 1 %>월
		
		<%
		if (month >= 12)
			out.println("<a>▶</a>");
		else
			out.println("<a href='Practice_C_04.jsp?YEAR=" + year + "&MONTH=" + (month+1) + "'>▶</a>");
		%>
	</td>
	<td style="border:none; text-align:right;"><%=displayYear %>-<%=displayMonth + 1 %>-<%=displayDate %></td>
</tr>
</table>

<table>
<tr>
	<%
	out.println("<td class='sun'>일</td>");
	for (int i = 2; i < 7; i++)
		out.print("<td>" + days[i] + "</td>");
	out.println("<td class='sat'>토</td>");
	%>
</tr>
<%
// 첫 주 (공백 + 날짜)
out.println("<tr>");
for (int i = 1; i < startDay; i++, count++)
	out.println("<td>&nbsp;</td>");
for (; count < 7; count++, nowDate++) {
	if (count % 7 == 0)
		out.println("<td class='sun'>" + nowDate + "</td>");
	else if (count % 7 == 6)
		out.println("<td class='sat'>" + nowDate + "</td>");
	else
		out.println("<td>" + nowDate + "</td>");
}
out.println("</tr>");

// 중간 주 ~ 마지막 주 (날짜만)
for (; nowDate <= end; count++, nowDate++) {
	if (count % 7 == 0)
		out.println("<tr><td class='sun'>" + nowDate + "</td>");
	else if (count % 7 == 6)
		out.println("<td class='sat'>" + nowDate + "</td></tr>");
	else
		out.println("<td>" + nowDate + "</td>");
}

// 마지막 주 (공백만)
if (count % 7 != 0) {
	for (; count % 7 != 0; count++)
		out.println("<td>&nbsp;</td>");
	out.println("</tr>");
}
%>
</table>

</body>
</html>