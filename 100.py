a = 1
hprev, hprevprev = 1, 0
kprev, kprevprev = 0, 1
cnt = 0
LIMIT = 1000000000000
while 1:
	num = a * hprev + hprevprev
	den = a * kprev + kprevprev
	cnt += 1
	totballs = (num + 1) / 2
	blueballs = (den + 1) / 2
	if (totballs > LIMIT): 
		break
	hprevprev, hprev = hprev, num
	kprevprev, kprev = kprev, den
	if a == 1: a = 2
print totballs, blueballs

