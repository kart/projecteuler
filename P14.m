threeen(n)	;
	if ($data(memo(n)))  quit memo(n)
	if n=1  quit 1
	if n#2  do
	. set x=(3*n)+1
	else  do
	. set x=n/2
	if ($data(memo(x)))  do
	. set ans=1+memo(x)
	else  do
	. set ans=1+$$^threeen(x)
	set ans=1+$$^threeen(x)
	set memo(n)=ans
	quit ans

main		;
	read n
	set memo(1)=1
	set max=-1
	for i=1:1:n  do
	. set cycle=$$^threeen(i)
	. if cycle>max  set max=cycle
	write !,max,!
	quit
