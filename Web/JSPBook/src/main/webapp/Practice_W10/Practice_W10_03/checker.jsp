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
<%
String action = request.getParameter("action");
if (action.equals("login")) {
	String user = request.getParameter("user");
	String passwd = request.getParameter("passwd");
	if (!user.equals("") && passwd.equals("1234")) {
		session.setAttribute("user", user);
	}
	response.sendRedirect("init.jsp");
}
else {
	session.invalidate();
	response.sendRedirect("init.jsp");
}
%>
</body>
</html>