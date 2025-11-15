<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Session Object: 01</title>
</head>
<body>
<form name="addr" action="session_02.jsp" method="post">
	아이디: <input type="text" name="username" /><br>
	패스워드: <input type="password" name="passwd" /><br>
	<input type="submit" value="로그인" />
	<input type="button" value="취소" />
</form>
</body>
</html>