; The tricky part is to identify the upper bound. Otherwise, it is just plain iteration
; The framework can be directly used to solve problem 34
main	;
	set d(0)=1
	set d(1)=1
	set d(2)=2
	set d(3)=6
	set d(4)=24
	set d(5)=120
	set d(6)=720
	set d(7)=5050
	set d(8)=40320
	set d(9)=362880
	set oversum=0
	for i=10:1:2903040 do
	. set n=i
	. set sum=0
	. for  quit:n=0  do
	. . set last=n#10
	. . set sum=sum+d(last)
	. . set n=n\10
	. if sum=i  set oversum=oversum+sum
	write oversum,!
	quit
