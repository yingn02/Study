rollout test "hello world~"
(
	colorpicker cp "colorpicker " color:(color 0 255 100)
	
	on cp changed co do
	(
		format "color: %\n" co
		
		-- box01 가 있으면 wirecolor를 바꾼다
		if $box01 != undefined do
			$box01.wirecolor = co
	)
)

createdialog test   width:150
