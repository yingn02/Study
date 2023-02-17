rollout test "hello world~" 
(
	spinner sp1 "spinner ¿‘¥œ¥Ÿ"  range:[-50,100,5] scale:2  type:#integer
	
	on sp1 changed val do
	(
		format "changed %\n" val
	)
)
createdialog test
