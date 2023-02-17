p = sphere  segments:12
convertToPoly p
for i = 1 to 100 do			-- 1 부터 100 까지 for문 돌리기
(
	-- 랜덤으로 face 선택하기
	polyop.setFaceSelection p #{(random 1 p.faces.count)}
	p.extrudeFaces (random 5.0 10.0)		-- extrude Face 한다
)
