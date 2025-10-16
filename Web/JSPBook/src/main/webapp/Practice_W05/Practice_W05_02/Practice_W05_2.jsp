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
	input {
		background-color="yellow";
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
			<form>
				<table width="100%">
					<tr>
						<td/>
						<td>
							<select name="type">
								<option>학부생</option>
								<option>교직원</option>
								<option>교수</option>
							</select>
						</td>
					</tr>
					<tr>
						<td>아이디</td>
						<td><input class="input" type="text" name="id"></td>
					</tr>
					<tr>
						<td>비밀번호</td>
						<td><input type="password" name="pwd"></td>
					</tr>
				</table>
				<input type="submit" name="login" value="로그인">
				<input type="submit" name="sign_up" value="가입하기">
			</form>
		</td>
	</tr>
	</table>
</body>
</html>