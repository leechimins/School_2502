<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 17</title>
</head>
<body>
<h4>전달된 파라미터 이름들</h4>
<%
Enumeration<String> paramNames = request.getParameterNames();
while (paramNames.hasMoreElements()) {
	String name = (String)paramNames.nextElement();
	out.println(name + "<br>");
}
%>
<hr>
<%
paramNames = request.getParameterNames();
while (paramNames.hasMoreElements()) {
	String name = (String)paramNames.nextElement();
	String value = request.getParameter(name);
	out.println(name + ":" + value + "<br>");
}
%>

</body>
</html>