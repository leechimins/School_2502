<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>주소록 입력</title>
</head>
<body>
<table>
<form name="addr" action="control.jsp" method="post">
	<tr>
		<td>이름:</td>
		<td><input type="text" name="name" /></td>
	</tr>
	<tr>
		<td>전화번호:</td>
		<td><input type="text" name="tel" /></td>
	</tr>
	<tr>
		<td>주소:</td>
		<td><input type="text" name="address" /></td>
	</tr>
	<tr>
		<td colspan=2 style="text-align:center;"><input type="submit" value="등록" /></td>
	</tr>
</form>
</table>
</body>
</html>