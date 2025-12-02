<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Process</title>
</head>
<body>

<h1>Processing Parameters</h1>
id: ${param.id }<br>
pw: ${param.pw }<br>
gender: ${param.gender }<br>
phone1: ${param.phone1 }<br>
phone2: ${param.phone2 }<br>
phone3: ${param.phone3 }<br>
email: ${param.email }<br>
birth: ${param.birth }<br>
<hr>
<%
String birth = request.getParameter("birth");
int age = 2025 - Integer.parseInt(birth.split("-")[0]);
pageContext.setAttribute("age", age);
%>

${param.id }님은 ${pageScope.age >= 19 ? "성년입니다." : "성년이 아닙니다."}
</body>
</html>