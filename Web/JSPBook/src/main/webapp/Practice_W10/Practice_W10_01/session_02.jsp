<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Session Object: 02</title>
</head>
<body>
<%=request.getParameter("username") %>님 환영합니다.<br>
<br>
세션 ID: <%=session.getId() %><br>
세션 지속시간(default): <%=session.getMaxInactiveInterval() %>초<br>
<br>
<a href="session_03.jsp" target="_blank">session_03.jsp로 가기</a>
</body>
</html>