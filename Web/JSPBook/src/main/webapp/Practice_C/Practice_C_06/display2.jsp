<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Display2</title>
</head>
<body>
<h2>등록된 일정</h2>
<ul>
<%
HashMap<String, String> dmap = (HashMap<String, String>)session.getAttribute("diary");
if (dmap == null) {
    dmap = new HashMap<String, String>();
    dmap.put("2025-10-03", "개천절");
    dmap.put("2025-09-01", "개강일");
    dmap.put("2025-12-18", "기말고사");
    dmap.put("2025-10-09", "한글날");
    session.setAttribute("diary", dmap);
}
for (String date: dmap.keySet()) {
	String task = dmap.get(date);
	out.println("<li>" + date + " : " + task + "</li>");
}
%>
</ul>
<hr>
<form name="find" action="result.jsp" method="post">
	년: <input type="text" name="year" />
	월: <input type="text" name="month" />
	<input type="submit" value="찾기" />
</form>
</body>
</html>