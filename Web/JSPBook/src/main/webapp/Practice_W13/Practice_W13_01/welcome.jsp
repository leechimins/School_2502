<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

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
<h2>입력 내용</h2>
아이디: ${empty user.id ? "아이디가 입력되지 않았습니다." : user.id}<br>
패스워드: ${empty user.passwd ? "패스워드가 입력되지 않았습니다." : user.passwd}<br>
<hr>
${!empty user.id and user.passwd == "1234" ? "로그인 성공" : "로그인 실패"}
</body>
</html>