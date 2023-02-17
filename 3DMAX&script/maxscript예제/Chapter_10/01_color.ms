width = 10

widthStep = 255.0/(width-1)		-- color 의 간격값 계산
for i in 0 to width-1 do
(
	p = [i*10,0,0]				-- box 의 위치 계산
	c = color (i*widthStep) 0 0		-- red 를 단계적으로 증가
	box  length:10  width:10  height:10  pos:p  wirecolor:c
	
	p = [i*10,-20,0]
	c = color 0  (i*widthStep) 0	-- green 를 단계적으로 증가
	box  length:10  width:10  height:10  pos:p  wirecolor:c
	
	p = [i*10,-40,0]
	c = color 0  0  (i*widthStep)	-- blue 를 단계적으로 증가
	box  length:10  width:10  height:10  pos:p  wirecolor:c	
)
