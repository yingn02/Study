rollout test "hello world~"
(
	local  count = 0
	timer clock "timer" interval:1000  --1초 간격
	label test "1"

	on clock tick do
	(
		count +=1
		test.text = count as string
		$myBox.pos += [0,0,10]	-- mybox란 이름의 box를 이동 시킨다
	)

	on test open do
	(
		box name:"myBox"
	)

)

createdialog test
