<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>include action</title>
	<style>
		body {
			text-align: center;
		}
	</style>
</head>
<body>
	<h1>include 액션 연습</h1>
	<hr>
	<jsp:include page="greeting.jsp">
		<jsp:param name="name" value="Dongduk University" />
		<jsp:param name="date" value="2011/04/05" />
		<jsp:param name="krName" value='<%=java.net.URLEncoder.encode("관리자") %>'/>
	</jsp:include>
</body>
</html>