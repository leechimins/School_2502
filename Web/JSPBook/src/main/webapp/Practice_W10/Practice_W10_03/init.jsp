<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>이클래스 로그인</title>
<style>
	div {
		text-align: center;
	}
	table {
		margin: auto;
	}
	img {
		width: 100%;
		height: auto;
	}
	.info {
		font-weight: bold;
	}
	.user {
		background-color: #FFFF99;
	}
</style>
</head>
<body>
<div><img src="eclass_title.jpg"/></div>
<div><h2>로그인</h2></div>
<hr>
<table>
<tr>
	<td><img src="eclass_logo.png"/></td>
	<td>
		<%if (session.getAttribute("user") == null) { %>
		<jsp:include page="login.jsp" />
		<%
		}
		else {
			pageContext.include("welcome.jsp");
		}
		%>
	</td>
</tr>
</table>
</body>
</html>