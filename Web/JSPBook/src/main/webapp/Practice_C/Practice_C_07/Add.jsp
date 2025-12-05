<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
HashMap<String, String> dmap = (HashMap<String, String>)session.getAttribute("diary");
dmap.put(request.getParameter("date"), request.getParameter("task"));
session.setAttribute("diary", dmap);

String[] ymd = request.getParameter("date").split("-");

response.sendRedirect("Calendar.jsp?YEAR=" + ymd[0] + "&MONTH=" + ymd[1]);
%>
</body>
</html>