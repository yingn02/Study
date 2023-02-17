mybox = box()
radius = 50
num = 101
step = 360 / num as float

for i in 1 to num do
(
	-- circle 공식 적용
	x = radius * sin(i * step)
	y = radius * cos(i* step)
	with animate on				-- 0 부터 100까지 애니메이션 한다
	(
		at time (i-1) mybox.pos =[x,y,0]
	)
)
