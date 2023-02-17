c = cylinder heightsegs:5 sides:10 radius:5		-- cylinder 생성
select c						-- cylinder 선택
max modify mode			-- modify 모드로 간다
myBend = Bend()			-- bend 를 myBend 변수에 저장
addModifier c myBend		-- modifier를 추가한다
$.modifiers[#bend].angle = 30		-- angle 값을 30 적용


--ben=c.modifiers[#bend]
--deleteModifier c ben