rollout test "hello world~"
(
	checkbox chk "checkbox �Դϴ�"  width:200
	
	on chk changed state do
	(
		format "checkbox %\n" state
	)
)

createdialog test width:200 height:70
