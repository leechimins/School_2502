<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
HashMap<String, String> dmap = (HashMap<String, String>)session.getAttribute("diary");
if (dmap == null) {
    dmap = new HashMap<String, String>();
    session.setAttribute("diary", dmap);
}
dmap.put(request.getParameter("date"), request.getParameter("task"));
session.setAttribute("diary", dmap);
response.sendRedirect("display.jsp");
%>
</body>
</html>