rollout test "hello world~"
(
	edittext et "Edittext"

	on et changed txt do		-- 한글자씩 친경우의 이벤트
	(
		print txt
	)
	
	on et entered txt do		-- enter를 친경우의 이벤트
	(
		format "entered: %\n" txt
	)
)

createdialog test
