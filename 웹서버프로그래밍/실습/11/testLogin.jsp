<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title> response Redirection </title>
</head>
<body>
	<hr>
	<%
		request.setCharacterEncoding("utf-8");
		String u_id = request.getParameter("id");
		String u_pw = request.getParameter("passwd");
		
		if(u_id.equals("hansung") && u_pw.equals("1234"))
		{
	        session.setAttribute("loginUser",u_id); //아이디로 loginUser라는 세션을 만들겠다. 
			response.sendRedirect("main.jsp");
		}
		else
		{
			response.sendRedirect("login.jsp");
		}
	%>
</body>
</html>

