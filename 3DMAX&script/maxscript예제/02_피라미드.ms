baseWidth = 210		-- 맨아래 box 넓이
baseHeight = 10		-- box 높이

w = baseWidth
count = 0
hPos = 0
while w > 0 do
(
	-- 루프중 esc 누르면 탈출
	if keyboard.escPressed do exit
	
	--	box 생성 (색상은 노랑색)
	box width:w length:w height:baseHeight pos:[0,0,hPos]  wirecolor:yellow	
	w = w - baseHeight * 2		-- 현재 box의 넓이를 계산
	count +=1										-- 계속 증가되는 인덱스
	hPos = count * baseHeight		-- 현재 box 의 높이를 계산
)
