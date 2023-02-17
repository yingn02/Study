rollout test "hello world~"
(
	progressbar pbar
	button go_btn "go"


	on pbar clicked val do
	(
		format "clicked: %\n" val
	)
	
	on go_btn pressed do
	(
		delete $temp*				-- temp 란 이름을 가진 모든 오브젝트를 지움니다
		
		-- 랜덤으로 주전자 100개 생성
		for i in 1 to 100 do
		(
			rnd = random [-100,-100,0] [100,100,0] 
			tea = teapot  pos:rnd  name:("temp" + i as string)
			pbar.value = i
		)
	)
)

createdialog test   width:200
