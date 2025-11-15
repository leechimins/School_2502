<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>관리자 정보</title>
</head>
<body>
<%
Enumeration<String> paramNames = request.getParameterNames();
while (paramNames.hasMoreElements()) {
	String name = (String)paramNames.nextElement();
	Object attr = request.getParameter(name);
	if (attr != null) {
		application.setAttribute(name, attr);
	}
}
Date time = new Date(session.getCreationTime());
application.setAttribute("time", time);
%>

<h1>관리자 정보 출력</h1>
관리자 이름: <%=application.getAttribute("user") %><br>
로그인 위치: <%=application.getAttribute("location") %><br>
로그인 시각: <%=application.getAttribute("time") %><br>
<br>
출력시 세션: <%=session.getId() %>
</body>
</html>