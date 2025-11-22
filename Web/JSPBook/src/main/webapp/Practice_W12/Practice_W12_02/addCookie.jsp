<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Add Cookie</title>
</head>
<body>
<%! int count = 0; %>
<%
String index = "cart_"+String.format("%03d", count);
Cookie obj = new Cookie(index, request.getParameter("obj"));
response.addCookie(obj);
count++;
%>
쿠키로 추가: cart_<%=index %>=<%=request.getParameter("obj") %>
<br><br>
<a href="shopping.jsp">장바구니로 이동</a>
</body>
</html>