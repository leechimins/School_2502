<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>로그인 페이지</title>
</head>
<body>
<jsp:useBean id="user" class="jspbook.w09.Login" />
<jsp:setProperty name="user"  property="*"/>
<%
if (user.checkLogin() == 0) {
	out.println(user.getId() + "님 환영합니다.");
}
if (user.checkLogin() == 1) {
	out.println("잘못된 아이디: " + user.getId());
}
if (user.checkLogin() == -1) {
	out.println("잘못된 패스워드: " + user.getPasswd());
}
%>
</body>
</html>