<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Calendar</title>
	<style>
	table, td {
		border-collapse: collapse;
		border: 1px solid grey;
	}
	td {
		text-align: center;
		width: 70px;
		height: 40px;
	}
	</style>
</head>
<body>
	<%@page import="java.util.Calendar" %>
	<%!
	Calendar cal = Calendar.getInstance();
	String[] days = { "None", "일", "월", "화", "수", "목", "금", "토" };
	int year, month, date, start, end, startDay, count = 0;
	%>
	
	<%
	year = 2016;
	month = 11;
	
	cal.set(year, month - 1, 1);
	
	startDay = cal.get(Calendar.DAY_OF_WEEK);
	start = cal.getMinimum(Calendar.DATE);
	end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	%>
	
	<h2><%=year %>년 <%=month %>월</h2>
	<hr>
	
	<table>
	<tr>
		<%
		out.println("<td><font color='red'>일</font></td>");
		for (int i = 2; i < 7; i++) {
			out.print("<td>");
			out.print(days[i]);
			out.println("</td>");
		}
		out.println("<td><font color='blue'>토</font></td>");
		%>
	</tr>
	<%
	// 첫 주 (공백 + 날짜)
	out.println("<tr>");
	for (int i = 1; i < startDay; i++, count++)
		out.println("<td>&nbsp;</td>");
	for (date = start; count < 7; count++, date++)
		out.println("<td>" + date + "</td>");
	out.println("</tr>");
	
	// 중간 주 ~ 마지막 주 (날짜만)
	for (; date <= end; date++, count++) {
		if (count % 7 == 0)
			out.println("<tr>");
		
		out.println("<td>" + date + "</td>");
		
		if (count % 7 == 6)
			out.println("</tr>");
	}
	
	// 마지막 주 (공백만)
	for (; count % 7 != 6; count++)
		out.println("<td>&nbsp;</td>");
	out.println("</tr>");
	%>
	</table>
</body>
</html>