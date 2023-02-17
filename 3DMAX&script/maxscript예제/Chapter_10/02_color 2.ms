delete $tempBox*		-- tempBox 란 이름을 가진 box가 있을 경우 지운다
width = 20		-- 가로 box 갯수 설정
height = 20		-- 세로 box 갯수 설정


wstep = 255.0/(width-1)		-- 증가되는 wstep 계산
vstep = 255.0/(height-1)		-- 증가되는 vstep 계산
for i in 0 to width-1 do
(
	for j in 0 to height-1 do
	(
		p = [i * 10, j * 10, 0]		-- box의 위치 계산
		myColor = black			-- 초기 color 는 black
		myColor.v = j * vstep		-- color value을 계산
		myColor.s = 255			-- color 의 채도값 255
		myColor.h = i * wstep		-- color hue 값 계산

		-- box 생성
		box  length:10  width:10  height:10  pos:p  \
			name:"tempBox"  wirecolor:myColor
	)
)
