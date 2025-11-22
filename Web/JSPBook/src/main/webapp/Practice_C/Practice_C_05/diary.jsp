<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Diary</title>
</head>
<body>
<form name="diary" action="add.jsp" method="post">
	날짜: <input type="date" name="date" />
	일정: <input type="text" name="task" />
	<input type="submit" value="일정 더하기" />
</form>
</body>
</html>