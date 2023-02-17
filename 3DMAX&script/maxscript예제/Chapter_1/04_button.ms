rollout test "hello world~" 
(
	button my_btn "Button"
	
	on my_btn pressed do
	(
		messagebox "누르기"
	)
	
	on my_btn rightclick do
	(
		messagebox "오른 버튼 누르기"	
	)
)
createdialog test
