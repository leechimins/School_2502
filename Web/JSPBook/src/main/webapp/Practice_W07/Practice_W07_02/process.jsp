<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice 22</title>
</head>
<body>

<%!
String[] mChoices = { "hobby" };
String[] hobbyNames = { "뉴스", "맛집", "책", "영화", "여행" };
String[] telCompany = { "010", "011", "017", "070" };
String[] gNames = { "남", "여" };

ArrayList<String> getParameterNames(HttpServletRequest request) {
	ArrayList<String> result = new ArrayList<String>();
	Enumeration<String> paramNames = request.getParameterNames();
	while (paramNames.hasMoreElements()) {
		String name = (String)paramNames.nextElement();
		result.add(name);
	}
	
	return result;
}

boolean isMultipleChoice(String paramName) {
	return Arrays.asList(mChoices).contains(paramName);
}
%>

<h2>Processing Parameters</h2>
<%
ArrayList<String> names = getParameterNames(request);
for (String name: names) {
	if (isMultipleChoice(name)) {
		out.println(name + ": ");
		String[] result = request.getParameterValues(name);
		for (String item: result) {
			out.print(item + "/");
		}
		out.println("<br>");
	}
	else {
		out.println(name + ": " + request.getParameter(name) + "<br>");
	}
}
%>
<hr>
<%
for (String name: names) {
	if (isMultipleChoice(name)) {
		out.println(name + ": ");
		String[] result = request.getParameterValues(name);
		for (String item: result) {
			int pos = Integer.parseInt(item);
			out.print(hobbyNames[pos] + "/");
		}
		out.println("<br>");
	}
	else if (name.equals("gender")) {
		int index = Integer.parseInt(request.getParameter(name));
		out.println(name + ": " + gNames[index] + "<br>");
	}
	else if (name.equals("phone1")) {
		int index = Integer.parseInt(request.getParameter(name));
		out.println(name + ": " + telCompany[index] + "<br>");
	}
	else {
		out.println(name + ": " + request.getParameter(name) + "<br>");
	}
}
%>

</body>
</html>