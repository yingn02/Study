rollout test "hello world~"
(
	radiobuttons rad1   "radiobuttons1 입니다"  labels:#("a","b","c")
	radiobuttons rad2   "radiobuttons2 입니다" labels:#("min", "max","center") default:3 pos:[40,50]
	

	on rad1 changed val do
	(
		format "rad1: %\n" val
	)
	
	on rad2 changed val do
	(
		format "rad2: %\n" val
	)
)

createdialog test height:100  width:200
