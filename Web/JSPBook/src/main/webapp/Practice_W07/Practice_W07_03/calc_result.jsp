<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<%@ page import="java.util.*" %>
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
<%

int num1 = Integer.parseInt(request.getParameter("num1"));
String op = request.getParameter("op");
int num2 = Integer.parseInt(request.getParameter("num2"));
int result = num1;
switch (op) {
	case "+":
		result += num2;
		break;
	case "-":
		result -= num2;
		break;
	case "*":
		result *= num2;
		break;
	case "/":
		result /= num2;
		break;
	default:
		result = 0;
		break;
}

%>

<body>
	<table>
	<tr>
		<th colspan="4">CalCuLaTor</th>
	</tr>
	<tr>
		<td><img src="cal.jpg"/></td>
		<td width="30px"/>
		<td>
			<form name="form" style="line-height: 2;">
			<input class="input" type="text" name="num1" value=<%= num1%> size=10 readonly><br>
			<%= op%>
			<br>
			<input class="input" type="text" name="num2" value=<%= num2%> size=10 readonly><br>
			=<br>
			<input class="input" type="text" name="rslt" value=<%= result%> size=10 readonly>
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