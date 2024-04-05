<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title> Test </title>
</head>
<body>
	<hr>
	<%
		request.setCharacterEncoding("utf-8");
		String u_id = request.getParameter("id");
		String u_pw = request.getParameter("passwd");
		
		if(u_id.equals("hansung") && u_pw.equals("1234"))
		{
			out.println("Home > 로그인 인증받은 회원만 제공되는 페이지 <hr>");
			out.println("[ " + u_id + " ]님이 입장하였습니다.<br> ");
		}
		else
		{
			response.sendRedirect("login.jsp");
		}
	%>
	
	<%
		//세션 ID를 가져오기
		String sessionId = request.getSession().getId();
		
		//세션 ID를 출력하기
		out.println("세션 ID는 " + sessionId + "<br>");
	%>
	
	<br>
	-- 세션 유효시간 변경 전 -- <br>
	<%
		int s_time = session.getMaxInactiveInterval() / 60;
		out.println("세션의 유효시간 : [ " + s_time + " 분 ] <br><br>");
	%>
	
	-- 세션 유효시간 변경 후 -- <br>
	<%
		session.setMaxInactiveInterval(60 * 5);
		s_time = session.getMaxInactiveInterval() / 60;
		out.println("세션의 유효시간 : [ " + s_time + " 분 ]");
	%>
	
	<hr>
    로그인 접속 후 세션을 유지한 시간 출력하기 <br>
	<%
		long last_time = session.getLastAccessedTime();
		long start_time = session.getCreationTime();
		long keping_time = (last_time - start_time)/60000;
		
		out.println("최소 접근 시간 : [ " + start_time + "] <br>");
		out.println("마지막 접근 시간 : [ " + last_time + "] <br>");
		out.println("경과 시간 : [ " + keping_time + " 분 ] <br>");
	%>
</body>
</html>

