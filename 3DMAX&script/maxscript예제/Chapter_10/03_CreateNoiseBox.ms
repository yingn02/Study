-- Noise 로 박스를 배치하기 위한 함수
fn makeNoiseBoxFn  Lengthseg  Widthseg  scaleV  randV  z  offset =
(
	if randV == undefined do return undefined
		
	delete $tempNoiseBox*		-- $tempNoiseBox 이름의 오브젝트 모두 지우기

	-- 2중 for문
	for y in 0 to Lengthseg do
	(
		for x in 0 to Widthseg do
		(
			n = noise4 ([x*scaleV,y*scaleV,0]+offset)  randV	-- noise4 를 이용해서 box에 높이 설정
			hei =  abs (n*z)		-- box의 height 값 설정. 여기서는 (-)숫자가 나올수도 있기 때문에 abs를 사용한다
			
			-- box color 설정
			col = [50,50,50]*hei
			if col.x >= 255 or col.y >= 255 or col.z >=255 do 
			(
				col = [255,255,255]
			)
				
			-- box 생성
			box width:1 length:1 height:hei  pos:[x,y,0] name:"tempNoiseBox"  wirecolor:col
		)
	)
)


try( destroydialog CreateNoiseBox_roll)catch()		-- 다이알로그가 있다면 지우기

rollout CreateNoiseBox_roll "Create NoiseBox"
(
	local randomNum					-- random 숫자를 저장하기 위한 변수
	
	spinner Lengthseg_spi "Length Segs: "  range:[2,1000,10] type:#integer
	spinner Widthseg_spi "Width Segs: "  range:[2,1000,10] type:#integer
	spinner scale_spi "Scale: "  range:[0,1000,0.1]  scale:0.01
	spinner z_spi "z: "  range:[0,1000,10]
	spinner offsetX_spi "offset X: "  range:[-1000,1000,0]  scale:0.01
	spinner offsetY_spi "offset Y: "  range:[-1000,1000,0]  scale:0.01
	button create_btn "Create !!"  offset:[0,20]
	
	
	on Lengthseg_spi changed val do
		makeNoiseBoxFn   Lengthseg_spi.value  Widthseg_spi.value  scale_spi.value  randomNum  z_spi.value	\
			[offsetX_spi.value,offsetY_spi.value,0]
		
	on Widthseg_spi changed val do
		makeNoiseBoxFn   Lengthseg_spi.value  Widthseg_spi.value  scale_spi.value  randomNum  z_spi.value	\
			[offsetX_spi.value,offsetY_spi.value,0]	

	on scale_spi changed val do
		makeNoiseBoxFn   Lengthseg_spi.value  Widthseg_spi.value  scale_spi.value  randomNum  z_spi.value	\
			[offsetX_spi.value,offsetY_spi.value,0]	

	on z_spi changed val do
		makeNoiseBoxFn   Lengthseg_spi.value  Widthseg_spi.value  scale_spi.value  randomNum  z_spi.value	\
			[offsetX_spi.value,offsetY_spi.value,0]
	
	on offsetX_spi changed val do
		makeNoiseBoxFn   Lengthseg_spi.value  Widthseg_spi.value  scale_spi.value  randomNum  z_spi.value  \
			[offsetX_spi.value,offsetY_spi.value,0]

	on offsetY_spi changed val do
		makeNoiseBoxFn   Lengthseg_spi.value  Widthseg_spi.value  scale_spi.value  randomNum  z_spi.value  \
			[offsetX_spi.value,offsetY_spi.value,0]
	
	on create_btn pressed do
	(
		randomNum = random -1.0 1.0
		
		-- makeNoiseBoxFn 함수 호출
		makeNoiseBoxFn   Lengthseg_spi.value  Widthseg_spi.value  scale_spi.value  randomNum  z_spi.value  [0,0,0]
	)
)
createdialog CreateNoiseBox_roll
