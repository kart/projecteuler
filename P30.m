; The tricky part is to identify the upper bound. Otherwise, it is just plain iteration
; The framework can be directly used to solve problem 34
main	;
	set d(0)=0
	set d(1)=1
	set d(2)=32
	set d(3)=243
	set d(4)=1024
	set d(5)=3125
	set d(6)=7776
	set d(7)=16807
	set d(8)=32768
	set d(9)=59049
	set oversum=0
	for i=2:1:354294  do
	. set n=i
	. set sum=0
	. for  quit:n=0  do
	. . set last=n#10
	. . set sum=sum+d(last)
	. . set n=n\10
	. if sum=i  set oversum=oversum+sum
	write oversum,!
	quit
