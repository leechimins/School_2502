<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<p class="info"><%=session.getAttribute("user") %>님 환영합니다.</p>
<form name="login" action="checker.jsp" method="post">
<input type="hidden" name="action" value="logout">
<input type="submit" value="로그아웃">
</form>
</body>
</html>