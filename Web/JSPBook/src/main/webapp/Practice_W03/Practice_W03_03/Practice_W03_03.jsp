<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Practice 06</title>
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
	<%!
	int i = 0;
	
	String printTimeTable(int dan) {
		String result = "";
		
   		result += "<td>";
    	for (int i = 1; i <= 9; i++) {
    		result += dan;
    		result += " * ";
    		result += i;
    		result += " = ";
    		result += (dan * i);
    		result += "<br>";
    	}
   		result += "</td>";

		return result;
	}
	%>
	
	<%
    out.println("<div align='center'>");
    out.println("<table>");
    
    for (int row = 2; row < 7; row += 4) {
    	out.println("<tr>");
	    for (i = row; i < row + 4; i++) {
   	%>
	<%= printTimeTable(i) %>
	<%
	    }
	  	out.println("</tr>");
    }

    out.println("</table>");
    out.println("</div>");
    %>
</body>
</html>