<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title> 가입 안내 </title>
</head>
<body>

<% 
	String u_id = request.getParameter("userID");
	String u_pw = request.getParameter("userPW");
	String u_mail = request.getParameter("userMAIL");
	String u_sex = request.getParameter("userSEX");
	
	String sql = "INSERT INTO members(id, passwd, email, sex) VALUES";
	sql += "('" + u_id + "','" + u_pw + "','" + u_mail + "','" + u_sex + "')";

	String driverName="com.mysql.jdbc.Driver";
	String url = "jdbc:mysql://localhost:3306/jspdb";
	String username = "root";
	String password = "gg7890";
	
	Class.forName(driverName);
	Connection conn = DriverManager.getConnection(url, username, password);
	Statement sm = conn.createStatement();
	
	int count = sm.executeUpdate(sql);
	if(count == 1){
		out.println("회원가입 성공!");
	}else{
		out.println("회원가입 실패!");
	}
	sm.close();
	conn.close();	
%>

</body>

</html>
