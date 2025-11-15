<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>간단 로그인</title>
</head>
<body>
<form name="login" action="tracking.jsp" method="post">
	관리자 이름: <input type="text" name="user" />
	관리자 위치: <input type="text" name="location" />
	<input type="submit" value="로그인" />
</form>
</body>
</html>