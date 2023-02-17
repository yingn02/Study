rollout test "hello world~"
(
	slider sli "slider ¿‘¥œ¥Ÿ"  range:[-100,100,0]
	
	on sli changed val do
	(
		print val
	)
)

createdialog test height:100  width:200
