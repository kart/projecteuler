def sumd(x):
	s = 0
	while x != 0:
		s += x % 10
		x = x / 10
	return s

maxs = -1
for i in range(2, 101):
	for j in range(2, 101):
		x = i ** j
		s = sumd(x)
		if s > maxs:
			maxs = s
			a = i
			b = j

print a, "^", b, " = ", maxs
