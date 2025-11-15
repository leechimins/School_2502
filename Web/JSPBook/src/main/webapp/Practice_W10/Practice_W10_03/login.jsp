<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<p class="info">회원님의 아이디와 비밀번호를 정확히 입력하세요.</p>
<form name="login" action="checker.jsp" method="post">
<table>
<tr>
	<td/>
	<td>
		<select name="type">
			<option value="학부생">학부생</option>
			<option value="교직원">교직원</option>
			<option value="교수">교수</option>
		</select>
	</td>
</tr>
<tr>
	<td>아이디</td>
	<td><input class="user" type="text" name="user"></td>
</tr>
<tr>
	<td>비밀번호</td>
	<td><input class="user" type="password" name="passwd"></td>
</tr>
</table>
<input type="hidden" name="action" value="login">
<input type="submit" value="로그인">
<input type="button" value="가입하기">
</form>
</body>
</html>