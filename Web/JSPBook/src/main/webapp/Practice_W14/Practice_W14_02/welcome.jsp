<%-- 컴퓨터학과 3학년 20221590 이지민
	 Internal Web Browser --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>로그인 페이지</title>
</head>
<body>
<jsp:useBean id="login" class="jspbook.w09.Login" scope="page"/>
<jsp:setProperty name="login"  property="*"/>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<c:set var="check" value="<%=login.checkLogin() %>"/>

<c:choose>
	<c:when test="${check == 0 }">
		<c:out value="${login.getId() }"/>님 환영합니다.
	</c:when>
	<c:when test="${check == 1 }">
		잘못된 아이디: <c:out value="${login.getId() }"/>
	</c:when>
	<c:otherwise>
		잘못된 패스워드: <c:out value="${login.getPasswd() }"/>
	</c:otherwise>
</c:choose>

</body>
</html>