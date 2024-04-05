<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>메인 페이지</title>
</head>
<body>
    
    <%
    if (session.getAttribute("loginUser")==null){ //loginUser 세션 객체가 존재하지 않는다면 login페이지로 다시 보내라
    	response.sendRedirect("login.jsp");
    }
    %>

	Home > 로그인 인증받은 회원만 제공되는 페이지
	<hr>
	저희 홈페이지에 방문해 주셔서 감사합니다. <br>
	즐거운 시간 되세요. <br>
	
	<form action="logout.jsp" name="logoutForm" method="get">
 		<input type="submit" value=" 로그아웃 ">
	</form>
	
</body>
</html>