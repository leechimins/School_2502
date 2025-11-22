<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Shopping Cart</title>
</head>
<body>
<h2>Shopping Cart</h2>
<form name="setting" action="addCookie.jsp" method="post">
마음에 드는 물건:
<select name="obj">
	<option>데스크탑</option>
	<option>노트북</option>
	<option>스마트폰</option>
	<option>모니터</option>
	<option>마우스</option>
	<option>키보드</option>
</select>
색상:
<input type="submit" value="담아두기" />
</form>
<hr>
<h2>나의 리스트</h2>
<%
Cookie[] cookies = request.getCookies();
if (cookies != null) {
	for (Cookie cookie : cookies) {
		if (cookie.getName().indexOf("cart_") >= 0) {
			out.println(cookie.getValue() + "<br>");
		}
	}
}
else {
	out.println("아직 물건을 담지 않았습니다.");
}
%>
</body>
</html>