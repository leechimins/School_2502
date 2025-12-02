<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Process</title>
</head>
<body>
<jsp:useBean id="user" class="jspbook.w09.UserBean" />
<jsp:useBean id="date" class="jspbook.w12.Date" />
<jsp:setProperty name="user"  property="*"/>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<h2>Processing Parameters</h2>

${date.parseDate(user.getBirth()) }
생일: <c:out value="${date.getYear() }"/>년
	${date.getMonth() }월 
	${date.getDay() }일
<br>
<br>
관심분야:<br>
<c:forEach var="h" items="${paramValues.hobby}" varStatus="status">
	[${status.count }] <c:out value="${h }"/> <br>
</c:forEach>
<hr>
<c:out value="${user.getId() }" />님은 
<c:if test="${2025 - date.getYear() >= 19}" var="flag">
	성년 입니다.
</c:if>
<c:if test="${!flag }">
	성년이 아닙니다.
</c:if>

</body>
</html>