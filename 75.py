from collections import deque

if __name__ == "__main__":
	primitive_queue = deque()
	primitive_queue.appendleft([3, 4, 5])
	primitives = []
	MAX_P = 1500000
	while len(primitive_queue):
		curr = primitive_queue.pop()
		a, b, c = curr[0], curr[1], curr[2]
		if (a + b + c <= MAX_P):
			primitives.append(curr)
			a1 = a - 2*b + 2*c
			b1 = 2*a - b + 2*c
			c1 = 2*a - 2*b + 3*c
			primitive_queue.appendleft([a1, b1, c1])
			a1 = a + 2*b + 2*c
			b1 = 2*a + b + 2*c
			c1 = 2*a + 2*b + 3*c
			primitive_queue.appendleft([a1, b1, c1])
			a1 = -1*a + 2*b + 2*c
			b1 = -2*a + b + 2*c
			c1 = -2*a + 2*b + 3*c
			primitive_queue.appendleft([a1, b1, c1])
	ans = {}
	for each_p in primitives:
		maxk = MAX_P / (sum(each_p))
		for k in range(1, maxk + 1):
			c = k * sum(each_p)
			if (c <= MAX_P):
				if c in ans:
					ans[c] += 1
				else:
					ans[c] = 1
			else:
				break
	count = 0
	for k,v in ans.iteritems():
		if v == 1:
			count += 1
	print count
