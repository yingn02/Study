theTeapot=teapot()		-- 주전자 생성
animate on 		-- 애니메이션 on
	at time 30		-- 30 프레임에 rotate 키 생성
		rotate theTeapot 360 z_axis
	
-- 카메라 생성	
cam=targetcamera pos:[200,0,100] target:theTeapot
renderFrames=#{1..30}		-- 프레임 저장 범위
-- bitmap 생성...파일은 avi 로 한다
b=bitmap 160 120 filename:"c:/temp/test.avi"
	
-- 프레임 범위 안에서 랜더링
for i = 1 to renderFrames.count do
(
	if renderFrames[i] then
	(
		at time i		-- 해당 프레임으로 이동
		-- 랜더링후 bitmap에 저장
		render 160 120 camera:cam to:b
		save b
	)
)
close b		-- bitmap 닫기
RAMPlayer "c:/temp/test.avi"  ""		-- RAMPlayer 로 동영상 보기
