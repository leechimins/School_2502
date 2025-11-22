<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Display</title>
</head>
<body>
<h2>등록된 일정</h2>
<ul>
<%
HashMap<String, String> dmap = (HashMap<String, String>)session.getAttribute("diary");
if (dmap == null) {
    dmap = new HashMap<String, String>();
    session.setAttribute("diary", dmap);
}
for (String date: dmap.keySet()) {
	String task = dmap.get(date);
	out.println("<li>" + date + " : " + task + "</li>");
}
%>
</ul>
<hr>
<a href="diary.jsp">일정 추가</a>
</body>
</html>