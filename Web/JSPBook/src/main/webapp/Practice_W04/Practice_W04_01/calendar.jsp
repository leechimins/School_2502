<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Insert title here</title>
	<style>
		td.in {
			border: 1px solid black;
		    border-collapse : collapse;
		    width: 40px;
		    height: 40px;
		}
		table.in {
		    border: 1px solid black;
		    border-collapse : collapse;
		}
		tr.dydlf {
			font-weight: bold;
		}
	</style>
</head>
<body>
	<%
    out.println("<div align='center'>");
    out.println("<table class='in'>");
    
    out.println("<tr class='dydlf'>");
    
    out.println("<td class='in'><font color='red'>일</font></td>");
    out.println("<td class='in'>월</td>");
    out.println("<td class='in'>화</td>");
    out.println("<td class='in'>수</td>");
    out.println("<td class='in'>목</td>");
    out.println("<td class='in'>금</td>");
    out.println("<td class='in'><font color='blue'>토</font></td>");
    out.println("</tr>");
    
    for (int i = 0; i < 4; i++) {
        out.println("<tr>");    	
    	for (int j = 0; j < 7; j++) {
    		out.println("<td class='in'>&nbsp;</td>");
    	}
        out.println("</tr>");
    }
    
    out.println("</table>");
    out.println("</div>");
    %>
</body>
</html>