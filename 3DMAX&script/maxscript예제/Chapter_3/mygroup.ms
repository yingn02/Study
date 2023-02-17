boxs=for i in 0 to 10 collect
(
	s=sin(i*36)*50
	box pos:[i*50,s,0]
)
group boxs name:"myGroup"