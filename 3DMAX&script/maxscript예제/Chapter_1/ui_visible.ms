rollout test "hello world~"
(
	local toggle = false
	groupbox gb "" width:170 height:80
	button btn1 "button1" pos:[30,30]
	checkbox chk1 "checkbox1" pos:[100,30]
	button btn2 "visible" pos:[60,100] width:80


	on btn2 pressed do
	(
		-- btn2를 누르면 숨고 보이는 것이 토글된다.
		if toggle == false then
		(
				-- btn1과 chk1를 숨긴다.
				btn1.visible = false
				chk1.visible = false

				toggle = true   -- toggle 변수는 true
		)
		else
		(
			-- btn1과 chk1를 보이게 한다
			btn1.visible = true
			chk1.visible = true

			toggle = false
		)
	)
)

createdialog test width:200 height:130