<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title> 회원 탈퇴 </title>
</head>
<body>

<% 
	Class.forName("com.mysql.jdbc.Driver");
	Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jspdb", "root", "gg7890");

	String u_id = request.getParameter("userID");
    String sql = "DELETE FROM members WHERE id = ?";
	
	PreparedStatement sm = conn.prepareStatement(sql);
	sm.setString(1, u_id);

	int count = sm.executeUpdate();
	
	if(count == 1){
		out.print("회원 탈퇴 성공!");
	}else{
		out.print("회원 탈퇴 실패!");
	}
	
	sm.close();
	conn.close();	
%>

</body>

</html>