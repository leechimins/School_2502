<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Practice 05</title>
	<style>
		table, td {
		    border: 1px solid black;
		}
		td {
		    width: 100px;
		    height: 200px;
		}
	</style>
</head>
<body>
	<%
    out.println("<div align='center'>");
    out.println("<table>");
    
    for (int row = 2; row < 7; row += 4) {
        out.println("<tr>");   
	    for (int i = row; i < row + 4; i++) {
    		out.println("<td>");
	    	for (int j = 1; j <= 9; j++) {
	    		out.print(i);
	    		out.print(" * ");
	    		out.print(j);
	    		out.print(" = ");
	    		out.print(i * j);
	    		out.println("<br>");
	    	}
    		out.println("</td>");
	    }
        out.println("</tr>");
    }
    
    out.println("</table>");
    out.println("</div>");
    %>
</body>
</html>