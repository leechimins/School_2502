<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>회원 가입</title>
<style>
	table, td {
		border: 1px solid black;
	    border-collapse : collapse;
	}
	td {
		width: 420px;
	}
	td.info {
		width: 80px;
		text-align: center;
		font-weight: bold;
		background-color: #ECECEC;
	}
</style>
</head>
<body>
	<p>
	<table>
		<tr>
			<td class="info" colspan="2">회원 가입</td>
		</tr>
		<form name="id_form">
			<tr>
				<td class="info">아이디</td>
				<td>
					<input type="text" name="id">
					<input type="submit" name="check" value="중복확인">
				</td>
			</tr>
		</form>
		<form name="sign_up_form">
			<tr>
				<td class="info">패스워드</td>
				<td>
					<input type="password" name="pswd">
				</td>
			</tr>
			<tr>
				<td class="info">성별</td>
				<td>
					<input type="radio" name="gender" value=0>남
					<input type="radio" name="gender" value=1 checked>여				
				</td>
			</tr>
			<tr>
				<td class="info">국적</td>
				<td>
					<form name="country_form">
						<input type="text" name="country" value="대한민국" readonly>
						<input type="submit" name="check" value="국적변경" disabled>
					</form>
				</td>
			</tr>
			<tr>
				<td class="info">휴대폰</td>
				<td>
					<select name="call0">
						<option>010</option>
						<option>02</option>
						<option>031</option>
					</select>
					- <input type="text" name="call1" maxlength=4 size=4>
					- <input type="text" name="call2" maxlength=4 size=4>
				</td>
			</tr>
			<tr>
				<td class="info">이메일</td>
				<td>
					<input type="text" name="email" pattern="[a-z0-9._%+\-]+@[a-z0-9.\-]+\.[a-z]{2,}$">
				</td>
			</tr>
			<tr>
				<td class="info">생일</td>
				<td>
					<input type="date" name="birthday">
				</td>
			</tr>
			<tr>
				<td class="info">관심분야</td>
				<td>
					<input type="checkbox" name="hobby" value=0>뉴스 
					<input type="checkbox" name="hobby" value=1 checked>맛집 
					<input type="checkbox" name="hobby" value=2>책 
					<input type="checkbox" name="hobby" value=3>영화 
					<input type="checkbox" name="hobby" value=4>여행 
				</td>
			</tr>
			<tr>
				<td class="info">가입인사</td>
				<td>
					<textarea name="hello" cols=65 rows=5 wrap="soft">회원들에게 간단한 가입인사를 남겨주세요</textarea>
				</td>
			</tr>
			<tr>
				<td class="info">증명사진</td>
				<td>
					<input type="file" name="face">
				</td>
			</tr>
			<tr>
				<td class="info" colspan="2">
					<input type="submit" name="sign_up" value="가입하기">
					<input type="reset" name="retry" value="다시작성">
				</td>
			</tr>
		</form>
	</table>
	</p>
</body>
</html>