<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Control</title>
</head>
<body>
<%
ArrayList<String> names = new ArrayList<String>();
Enumeration<String> paramNames = request.getParameterNames();
while (paramNames.hasMoreElements()) {
	String name = (String)paramNames.nextElement();
	names.add(name);
}

String result = "display.jsp?";

for (String name: names)
	result += name + "=" + request.getParameter(name) + "&";

response.sendRedirect(result);
%>


</body>
</html>