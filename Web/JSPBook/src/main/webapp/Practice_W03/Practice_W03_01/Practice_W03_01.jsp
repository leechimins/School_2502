<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Practice 04</title>
	<style>
		table, td {
		    border: 1px solid black;
		}
		td {
		    text-align: center;
		    width: 80px;
		    height: 30px;
		}
		tr.dydlf {
			font-weight: bold;
		}
	</style>
</head>
<body>
	<%
    out.println("<div align='center'>");
    out.println("<table>");
    
    out.println("<tr class='dydlf'>");
    
    out.println("<td><font color='red'>일</font></td>");
    out.println("<td>월</td>");
    out.println("<td>화</td>");
    out.println("<td>수</td>");
    out.println("<td>목</td>");
    out.println("<td>금</td>");
    out.println("<td><font color='blue'>토</font></td>");
    out.println("</tr>");
    
    for (int i = 0; i < 4; i++) {
        out.println("<tr>");    	
    	for (int j = 0; j < 7; j++) {
    		out.println("<td>&nbsp;</td>");
    	}
        out.println("</tr>");
    }
    
    out.println("</table>");
    out.println("</div>");
    %>
</body>
</html>