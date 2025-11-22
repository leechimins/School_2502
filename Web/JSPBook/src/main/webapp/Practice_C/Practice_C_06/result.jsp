<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Result</title>
</head>
<body>
<%
int count = 0;
HashMap<String, String> dmap = (HashMap<String, String>)session.getAttribute("diary");
String year = request.getParameter("year");
int month = Integer.parseInt(request.getParameter("month"));
String target = year + "-" + String.format("%02d", month);
%>

<h2><%=year %>년 <%=month %>월 일정</h2>
<ul>
<%
for (String date: dmap.keySet()) {
	String task = dmap.get(date);
	if (date.indexOf(target) >= 0) {
		count++;
		out.println("<li>" + date + " : " + task + "</li>");
	}
}
if (count == 0) {
	out.println("<li>일정 없음</li>");
}
%>
</ul>
</body>
</html>