def is_square(n):
	n = n ** 0.5
	return int(n) == n

def sqrt(n):
	return int(n ** 0.5)


def is_triangular(x):
	y = 8*x + 1
	if (is_square(y) and (0 == (sqrt(y) - 1) % 2)):
		return 1
	return 0

if __name__ == "__main__":
	f = open('42.in', 'r')
	for line in f:
		s = line[0:len(line) - 1]
		t = 0
		for c in s:
			t = t + (ord(c) - ord('A') + 1)
		if (is_triangular(t)):
			print s
	f.close()

