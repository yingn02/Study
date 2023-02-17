rollout batch_rename "batch rename"
(
	edittext br_et ""
	button rename_btn "rename"
	
	on rename_btn pressed do		-- 일괄적으로 rename 한다
	(
		count = 0
		undo on									-- undo 기능 추가
			for i in selection do		-- 선택한 오브젝트만 적용한다
			(
				count += 1
				na = formattedprint count format:"02d"	-- 숫자를 01, 02, 03 이런식으로 붙인다
				i.name =  br_et.text + na as string
			)
	)
)
rollout transform_rollout "Transform"
(
	button zero_btn "[0,0,0]"
	button rotate1_btn "rotate 90"  pos:[10,40]
	button rotate2_btn "rotate -90"  pos:[70,40]

	on zero_btn pressed do		-- 오브젝트 위치를 [0,0,0]으로
	(
		undo on
			for i in selection do
			(
				i.pos = [0,0,0]
			)
	)
	
	on rotate1_btn pressed do			-- 90도 회전
	(
		undo on
			rotate selection (EulerAngles 0 0 90)		
	)
	
	on rotate2_btn pressed do			-- 반대로 90도 회전
	(
		undo on
			rotate selection (EulerAngles 0 0 -90)
	)
	
)

rollout pivot_rollout "Pivot"
(
	button zero_btn "[0,0,0]" pos:[20,20]
	button center_btn "center" pos:[70,20]
	
	on zero_btn pressed do			-- pivot의 위치를 [0,0,0]으로
	(
		for i in selection do
			i.pivot = [0,0,0]
	)
	
	on center_btn pressed do		-- pivot의 위치를 center로
	(
		for i in selection do
			i.pivot = i.center
	)
)

rollout wirecolor_rollout "wirecolor"
(
	button red_btn "RED"  pos:[5,20]  width:30
	button green_btn "GREEN"  pos:[40,20]  width:50
	button blue_btn "BLUE"  pos:[95,20]  width:35
	
	on red_btn pressed do		-- wirecolor를 red 으로
	(
		for i in selection do
			i.wirecolor = red
	)
	
	on green_btn pressed do		-- wirecolor를 green 으로
	(
		for i in selection do
			i.wirecolor = green
	)

	on blue_btn pressed do			-- wirecolor를 blue 으로
	(
		for i in selection do
			i.wirecolor = blue
	)
)

rollout properties_rollout "Properties"
(
	checkbox renderable_cb "Renderable"
	checkbox castShadow_cb "Cast Shadows"
	
	on renderable_cb changed state do		-- renderable 토글
	(
		for i in selection do
			i.renderable = state
	)
	
	on castShadow_cb changed state do		-- cast shadow 토글
	(
		for i in selection do
			i.castShadows = state
	)
)

rollout hide_rollout "hide/freeze"
(
	button hide_btn "hide"  pos:[10,10]  width:50
	button unhide_btn "unhide All" pos:[65,10]
	button freeze_btn "freeze" pos:[10,40]  width:50
	button unfreeze_btn "unfreeze All" pos:[65,40]
	
	on hide_btn pressed do			-- hide 한다
	(
		for i in selection do
			hide i
	)
	
	on unhide_btn pressed do		-- unhide all 한다
	(
		max unhide all
	)
	
	on freeze_btn pressed do		-- freeze 한다
	(
		for i in selection do
			freeze i
		
		clearselection()				-- 선택을 해제한다
	)
	
	on unfreeze_btn pressed do		-- unfreeze all 한다
	(
		max unfreeze all
	)
)

rollout boundDummy_rollout "Bound Dummy"
(
	button dummy_btn "dummy"

	fn makeDummy  obj =
	(
		size = obj.max - obj.min			-- 사이즈를 구한다
		dummy boxsize:size  pos:obj.pos		-- dummy 생성
	)
	
	on dummy_btn pressed do			-- 바운딩 dummy 만들기
	(
		for i in selection do
			makeDummy i
	)
)

main = newRolloutFloater "my tools" 150 550		-- newRolloutFloater를 만든다
addRollout batch_rename main			-- rollout들을 추가한다
addRollout transform_rollout main
addRollout pivot_rollout main
addRollout wirecolor_rollout main
addRollout properties_rollout main
addRollout hide_rollout main
addRollout boundDummy_rollout main
