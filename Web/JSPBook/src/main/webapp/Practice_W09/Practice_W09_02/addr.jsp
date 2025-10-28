<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>주소록 입력</title>
</head>
<body>
<form name="addr" action="control.jsp" method="post">
	이름: <input type="text" name="name" /><br>
	전화번호: <input type="text" name="tel" /><br>
	주소: <input type="text" name="address" /><br>
	<input type="submit" value="등록" />
</form>
</body>
</html>