<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>

<body>
	Home > Person Information Inquiry
	<hr>
	<%
		request.setCharacterEncoding("UTF-8");
		String name = request.getParameter("name");
		String code = request.getParameter("code");
		String gender = request.getParameter("gender");
		String[] hobby = request.getParameterValues("hobby");
	%>
	
	이름: <%= name %><br><br>
	사원코드: <%= code %><br><br>
	성별: <%= gender %><br><br>
	취미:  
	<%
		if(hobby != null) {
			for(int i=0; i<hobby.length; i++) {
				out.println(" " + hobby[i]);
			}
		}
	%>
	<br>
	
</body>
</html>