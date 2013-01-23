from collections import deque

if __name__ == "__main__":
	primitive_queue = deque()
	primitive_queue.appendleft([3, 4, 5])
	primitives = []
	count = 0
	ans = 0
	M = 10
	while len(primitive_queue):
		curr = primitive_queue.pop()
		a, b, c = curr[0], curr[1], curr[2]
		curr = sorted(curr)
		if (count < 25):
			count += 1
			print curr
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
