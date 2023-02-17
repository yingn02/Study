minDan = 1
maxDan = 9

for i in minDan to maxDan do
(
	format "\n"
	format "< % ´Ü >\n" i
	for j in 1 to 9 do
		format "% x % = %\n" i j (i*j)
)
