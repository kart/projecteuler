def do_primitives(a, b, c, primitives):
	if (a + b + c > 1000):
		return 0
	primitives.append([a, b, c])
	a1 = a - 2*b + 2*c
	b1 = 2*a - b + 2*c
	c1 = 2*a - 2*b + 3*c
	do_primitives(a1, b1, c1, primitives)
	a2 = a + 2*b + 2*c
	b2 = 2*a + b + 2*c
	c2 = 2*a + 2*b + 3*c
	do_primitives(a2, b2, c2, primitives)
	a3 = -1*a + 2*b + 2*c
	b3 = -2*a + b + 2*c
	c3 = -2*a + 2*b + 3*c
	do_primitives(a3, b3, c3, primitives)

if __name__ == "__main__":
	primitives = []
	do_primitives(3, 4, 5, primitives)
	ans = {}
	maxv,maxk = -1, -1
	for p in primitives:
		for k in range(1,100):
			c = k * (p[0] + p[1] + p[2])
			if (c <= 1000):
				if c in ans:
					ans[c] += 1
				else:
					ans[c] = 1
			else:
				break
	for k, v in ans.iteritems():
		if maxv < v:
			maxv = v
			maxk = k
	print maxk, maxv
			

	
