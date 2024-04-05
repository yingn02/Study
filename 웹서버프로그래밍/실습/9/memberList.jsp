<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title> 회원 가입 명단 </title>
</head>
<body>

<% 
	
	String driverName="com.mysql.jdbc.Driver";
	Class.forName(driverName);

	Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jspdb", "root", "gg7890");
	
	Statement sm = conn.createStatement();
	ResultSet rs = sm.executeQuery("SELECT id, email FROM members");
	
	out.print("Home > 회원가입 명단 <hr>");
	
	String str = "";
	int count = 1;
	
	while(rs.next()){
		str = count + " : " + rs.getString("id") + " / " + rs.getString("email") + " / "  + "<br>";
		out.print(str);
		count++;
	}

	rs.close();
	sm.close();
	conn.close();	
%>

</body>

</html>

