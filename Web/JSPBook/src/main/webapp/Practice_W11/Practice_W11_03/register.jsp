<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>ch07</title>
</head>
<body>
<jsp:useBean id="user" class="jspbook.w09.UserBean" />
<jsp:setProperty name="user"  property="*"/>
<div style="text-align: center;">
<h2>등록내용</h2>
이름: <%=user.getId() %> <br>
패스워드: <%=user.getPw() %> <br>
이메일: <%=user.getEmail() %> <br>
성별: <%=user.getGender() %> <br>
생일: <%=user.getBirth() %>
<hr>
<%=user.makeStmt() %>
</div>
</body>
</html>