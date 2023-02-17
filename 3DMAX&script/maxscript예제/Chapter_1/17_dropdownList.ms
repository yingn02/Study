rollout test "hello world~"
(
	dropdownlist dd "dropdownlist" items:#("1","2","3","4","5","6","7") height:5
	
	on dd selected val do
	(
		format "dropdownlist:  %\n" val
	)
)

createdialog test   width:150
