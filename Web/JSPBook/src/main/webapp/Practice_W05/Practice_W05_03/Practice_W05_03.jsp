<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>이클래스 로그인</title>
<style>
	table, td {
		text-align: center;
		margin: auto;
	}
	td {
		height: 80px;
	}
</style>
</head>
<body>
	<table>
	<tr>
		<td colspan='2' bgcolor="32CCFE">CalCuLaTor</td>
	</tr>
	<tr>
		<td><img src="cal.jpg"/></td>
		<td>
			<form name="form">
				<input class="input" type="text" name="num1"><br>
				<select name="op">
					<option>+</option>
					<option>-</option>
					<option>*</option>
					<option>/</option>
				</select><br>
				<input class="input" type="text" name="num2"><br>
				<input class="input" type="submit" name="sms"><br>
				<input class="input" type="password" name="rslt" disabled>
			</form>
		</td>
	</tr>
	<tr>
		<td colspan='2' bgcolor="32CCFE">&nbsp;</td>
	</tr>
	</table>
</body>
</html>