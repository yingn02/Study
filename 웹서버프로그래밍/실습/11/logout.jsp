<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title> response 내장 객체 </title>
</head>
<body>
	안녕히가십시오<br>
	<form action="login.jsp" name="logForm2" method="get">
		<input type ="submit" value="다시로그인">
	</form>
	
	<% 
		session.removeAttribute("loginUser");
	%>
</body>
</html>

