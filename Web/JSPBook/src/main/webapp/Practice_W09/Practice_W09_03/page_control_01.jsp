<!-- 컴퓨터학과 3학년 20221590 이지민 -->
<!-- 내장 브라우저 -->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 04</title>
</head>
<body>
<form name="forward" action="page_control_02.jsp" method="post">
	아이디: <input type="text" name="id" /> 비밀번호: <input type="text" name="passwd" />
	<input type="submit" value="forward 전송" />
</form>

<form name="redirect" action="page_control_03.jsp" method="post">
	아이디: <input type="text" name="id" /> 비밀번호: <input type="text" name="passwd" />
	<input type="submit" value="sendRedirect 전송" />
</form>
</body>
</html>