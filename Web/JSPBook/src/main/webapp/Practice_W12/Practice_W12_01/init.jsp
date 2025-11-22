<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Init</title>
</head>
<body>
<%
String lang = "unknown";
String color = "black";
Cookie[] cookies = request.getCookies();
if (cookies != null) {
	for (Cookie cookie : cookies) {
		if (cookie.getName().equals("language")) {
			lang = cookie.getValue();
		}
		else if (cookie.getName().equals("color")) {
			color = cookie.getValue();
		}
	}
}
%>
<form name="setting" action="saveConfig.jsp" method="post">
언어:
<select name="lang">
	<option>한국어</option>
	<option>English</option>
</select>
색상:
<select name="color">
	<option>red</option>
	<option>green</option>
	<option>blue</option>
</select>
<input type="submit" value="저장하기" />
</form>
<hr>
<p style="color:<%=color %>;">
설정된 언어: <%=lang %><br>
설정된 색상: <%=color %>
</p>
</body>
</html>