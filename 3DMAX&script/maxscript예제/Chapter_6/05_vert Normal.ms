obj = torus()			-- torus 생성
convertToMesh obj		-- Editable_Mesh로 변환
vertNum = 1				-- 버텍스 인덱스는 1
pos = getvert obj vertNum			-- vertex 위치를 알아낸다
Normal = getNormal obj vertNum		-- Normal을 알아낸다
point pos:pos dir:Normal  axistripod:true  cross:false		-- point 생성
