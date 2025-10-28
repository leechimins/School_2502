<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>addr_form.jsp</title>
<style>
	table, td {
		border: 1px solid black;
	}
</style>
</head>
<body>
<h1 style="text-align: center;">주소록 등록</h1>
<hr>
<form name="form" action="addr_add.jsp" method="post">
<table>
<tr>
	<td>이름</td>
	<td><input type="text" name="name"></td>
</tr>
<tr>
	<td>전화번호</td>
	<td><input type="text" name="tel"></td>
</tr>
<tr>
	<td>이메일</td>
	<td><input type="text" name="email"></td>
</tr>
<tr>
	<td>성별</td>
	<td>
		<select name="gender">
			<option>남</option>
			<option>여</option>
		</select>
	</td>
</tr>
<tr>
	<td colspan="2">
		<input type="submit" value="확인" />
		<input type="button" value="취소" />
	</td>
</tr>
</table>
</form>
</body>
</html>