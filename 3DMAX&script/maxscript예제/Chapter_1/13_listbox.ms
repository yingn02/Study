rollout test "hello world~"
(
	listbox li "listbox"  items:#("one","two","three","four","five")
	
	on li selected val do
	(
		format "selected: %\n" val
	)
	
	on li doubleClicked val do
	(
		mgs = "doubleClicked: " + val as string
		messagebox mgs
	)
)

createdialog test height:200  width:200
