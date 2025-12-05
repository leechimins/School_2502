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

<jsp:useBean id="myDate" class="jspbook.w16.Date" scope="session" />
<jsp:useBean id="scheduler" class="jspbook.w16.Scheduler" scope="session" />

<%
myDate.setDate(request.getParameter("date"));
scheduler.add(myDate, request.getParameter("task"));
response.sendRedirect("Calendar.jsp?YEAR=" + myDate.getYear() + "&MONTH=" + myDate.getMonth());
%>
</body>
</html>