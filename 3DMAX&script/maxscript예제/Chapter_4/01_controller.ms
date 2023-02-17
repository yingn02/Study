t = teapot()

animate on
(
	frame = animationRange.end - animationRange.start
	tic = frame as integer / 160.0	-- NTSC time 160 ticks 은 1 frame 입니다
	rot = 360 / tic				-- 회전량을 계산
	for i in animationRange.start to animationRange.end do
	(
		at time i  rotate t  (eulerAngles 0 0 rot)	-- 주전자를 회전
	)
)

Con = t.rotation.controller.X_Rotation.controller	-- x_rotation 콘트롤러
selectkeys Con  (interval 20f 40f)			-- 20f 에서 40f 키를 선택
deletekeys Con #selection				-- 선택한 keys를 지운다

Con = t.rotation.controller.Y_Rotation.controller	-- y_rotation 콘트롤러
selectkeys Con  (interval 20f 40f)
deletekeys Con #selection

Con = t.rotation.controller.Z_Rotation.controller	-- z_rotation 콘트롤러
selectkeys Con  (interval 20f 40f)
deletekeys Con #selection
