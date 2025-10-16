<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>greeting message</title>
</head>
<body>
	<h3>greeting.jsp에서 출력한 메세지입니다.</h3>
	<%=request.getParameter("name") %>님 환영합니다.<br>
	오늘은 <%=request.getParameter("date") %>입니다.<br>
	<% String krName = request.getParameter("krName"); %>
	한국어 parameter 가져오기 : <%=java.net.URLDecoder.decode(krName) %>
</body>
</html>