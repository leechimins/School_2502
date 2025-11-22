<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Add cookie</title>
</head>
<body>
<%
Cookie lang = new Cookie("language", request.getParameter("lang"));
Cookie color = new Cookie("color", request.getParameter("color"));
lang.setMaxAge(60 * 3);
color.setMaxAge(60 * 3);
response.addCookie(lang);
response.addCookie(color);
%>
저장된 쿠키:<br>
language=<%=lang.getValue() %><br>
color=<%=color.getValue() %>
<hr>
<a href="init.jsp">설정으로 가기</a>
</body>
</html>