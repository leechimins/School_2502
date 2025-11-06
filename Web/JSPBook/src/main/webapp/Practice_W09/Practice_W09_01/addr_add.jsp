<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>addr_add.jsp</title>
<style>
	body {
		text-align: center;
	}
</style>

</head>
<body>
<h1>등록 내용</h1>
이름: <%=request.getParameter("name") %><br>
전화번호: <%=request.getParameter("tel") %><br>
이메일: <%=request.getParameter("email") %><br>
성별: <%=request.getParameter("gender") %><br>
<hr>
<a href="addr_form.jsp">주소 추가</a>
</body>
</html>