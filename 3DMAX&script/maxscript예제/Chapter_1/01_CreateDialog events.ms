rollout test "hello world~" 
(
	label x_la "x: " pos:[70,50]
	label y_la "y: " pos:[120,50]
	
	on test mousemove pos do
	(
		x_la.text = "x: " + pos.x as string	-- label 의 text에 마우스 위치(x) 를 출력
		y_la.text = "y: " + pos.y as string	-- label 의 text에 마우스 위치(y) 를 출력
	)
	
	on test open do
	(
		print "open~"
	)
	
	on test close do
	(
		print "close~"
	)
	
	on test lbuttondown pos do
	(
		messagebox "마우스 왼쪽 클릭"
	)

	on test mbuttondown pos do
	(
		messagebox "마우스 가운데 클릭"
	)

	on test rbuttondown pos do
	(
		messagebox "마우스 오른 클릭"
	)
)
createdialog test width:200 height:150
