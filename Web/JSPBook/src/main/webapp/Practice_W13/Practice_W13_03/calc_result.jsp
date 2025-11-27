<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Calculator</title>
<style>
	table, td, th {
		text-align: center;
		margin: auto;
	}
	th {
		height: 70px;
		background-color:#32CCFE;
		font-size: 40px;
		font-family:serif;
	}
	td {
		height: 70px;
	}
	input {
		text-align: center;
	}
</style>
</head>
<body>
<jsp:useBean id="user" class="jspbook.w09.Calculator" />
<jsp:setProperty name="user"  property="*"/>
<table>
<tr>
	<th colspan="4">CalCuLaTor</th>
</tr>
<tr>
	<td><img src="cal.jpg"/></td>
	<td width="30px"/>
	<td>
	<form name="form" style="line-height: 2;">
		<input class="input" type="text" name="num1" value=${user.num1 } size=10 readonly><br>
		${user.op }
		<br>
		<input class="input" type="text" name="num2" value=${user.num2 } size=10 readonly><br>
		=<br>
		<input class="input" type="text" name="rslt" value=${user.calc() } size=10 readonly>
	</form>
	</td>
	<td width="30px"/>
</tr>
<tr>
	<td colspan='4' bgcolor="32CCFE">&nbsp;</td>
</tr>
</table>

</body>
</html>