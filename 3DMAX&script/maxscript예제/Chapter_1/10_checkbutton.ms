rollout test "hello world~"
(
	checkbutton chkbtn "checkbutton" tooltip:"체크버튼 입니다"  highlightColor:(color 255 0 255)
	
	on chkbtn changed state do
	(
		format "checkbutton %\n" state
	)
	
	on chkbtn rightclick do
	(
		chkbtn.text = "hi ~~"		-- chkbtn 의 텍스트를 바꾼다
	)
)

createdialog test height:50
