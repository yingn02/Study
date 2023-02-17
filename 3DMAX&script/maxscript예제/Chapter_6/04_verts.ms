if classof $ == Editable_mesh do		-- Editable Mesh 일때만 동작
(
	selV = getVertSelection $		-- 선택한 vertex 들을 알아낸다

	for i in selV do
		$.verts[i].pos *= [1,1,0]		-- z축으로 0 만들기

	update $				-- 변형후 update 해야 한다
)
