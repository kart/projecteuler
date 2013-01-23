def is_palin(n):
	c = str(n)
	l = len(c)
	i,j = 0,l-1
	while ((i <= j) and (c[i] == c[j])):
		i,j = i+1,j-1
	if (i>j):
		return 1
	else:
		return 0
maxp = -1
for i in range(100,999):
	for j in range(100,999):
		p = i * j
		if (1 == is_palin(p) and (p > maxp)):
			maxp = p

print maxp
