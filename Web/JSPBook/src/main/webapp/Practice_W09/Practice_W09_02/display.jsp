<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>결과 출력</title>
</head>
<body>
<h1>response redirection 전달 내용</h1>
<hr>
<%
ArrayList<String> names = new ArrayList<String>();
Enumeration<String> paramNames = request.getParameterNames();
while (paramNames.hasMoreElements()) {
	String name = (String)paramNames.nextElement();
	names.add(name);
}

for (String name: names)
	out.println(name + " = " + request.getParameter(name) + "<br>");
%>


</body>
</html>