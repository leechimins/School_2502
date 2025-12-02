<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Practice 05</title>
	<style>
		table, td {
		    border: 1px solid black;
		    text-align: center;
		}
		td {
		    width: 100px;
		    height: 200px;
		}
	</style>
</head>
<body>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<table>
<c:forEach var="i" begin="2" end="9">
	<c:if test="${i % 4 == 2 }">
		<tr>
	</c:if>
	<td>
		<c:forEach var="j" begin="1" end="9">
			<c:out value="${i} * ${j} = ${i*j}" /> <br>
		</c:forEach>
	</td>
	<c:if test="${i % 4 == 1 }">
		</tr>
	</c:if>
</c:forEach>
</table>

</body>
</html>