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
		<p class="info">회원님의 아이디와 비밀번호를 정확히 입력하세요.</p>
		<form name="login" action="result.jsp" method="post">
			<table width="100%">
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
				<td><input class="user" type="text" name="id"></td>
			</tr>
			<tr>
				<td>비밀번호</td>
				<td><input class="user" type="password" name="pwd"></td>
			</tr>
			</table>
			<input type="submit" value="로그인">
			<input type="button" value="가입하기">
		</form>
	</td>
</tr>
</table>
</body>
</html>