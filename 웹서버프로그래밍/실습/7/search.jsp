<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>

<body>
	검색 결과
	<hr>
	<%
		request.setCharacterEncoding("UTF-8");
		String s = request.getParameter("query");
	%>
	검색어는 <%= s %>이군요.<br>
	좀 더 공부해서 검색해드리겠습니다.

</body>
</html>