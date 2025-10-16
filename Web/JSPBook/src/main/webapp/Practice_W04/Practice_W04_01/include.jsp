<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Practice 4-1</title>
	<style>
		td {
			text-align: center;
		}
		td.space {
		    width: 20px;
		}
	</style>
</head>
<body>
	<div align="center">
		<h2>include 지시어 연습</h2>
		<hr>
		<p>
			<table>
			<tr>
				<td><%@ include file="calendar.jsp" %></td>
				<td class="space">&nbsp;</td>
				<td valign="top"><%@ include file="news.jsp" %></td>
			</tr>
			</table>
		</p>
	</div>
</body>
</html>