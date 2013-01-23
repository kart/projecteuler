def sqrt(n):
	return int(n ** 0.5)

def is_square(n):
	n = n ** 0.5
	return int(n) == n

def is_triangular(x):
	y = 8*x + 1
	if (is_square(y) and (0 == (sqrt(y) - 1) % 2)):
		return 1
	return 0

def is_pentagonal(x):
	y = 24*x + 1
	if (is_square(y) and (0 == (sqrt(y) + 1) % 6)):
		return 1
	return 0

def is_hexagonal(x):
	y = 8*x + 1
	if (is_square(y) and (0 == (sqrt(y) + 1) % 4)):
		return 1
	return 0

def is_heptagonal(x):
	y = 40*x + 9
	if (is_square(y) and (0 == (sqrt(y) + 3) % 10)):
		return 1
	return 0

def is_octagonal(x):
	y = 12*x + 4
	if (is_square(y) and (0 == (sqrt(y) + 2) % 6)):
		return 1
	return 0

def add(d, num):
	if (num / 100 in d):
		d[num / 100].append(num)
	else:
		d[num / 100] = [num, ]

path = []
count = 0
def getcycle(s, start, exclude, cnt):
	global count
	count += 1
	if (cnt == 6):
		return 1
	for fig in range(0, len(exclude)):
		if (not exclude[fig]) and (start in s[fig]):
			exclude[fig] = 1
			for vv in s[fig][start]:
				if (getcycle(s, vv % 100, exclude, cnt + 1)):
					path.append(vv)
					exclude[fig] = 0
					return 1
			exclude[fig] = 0
	return 0

if __name__ == "__main__":
	tri,sq,pent,hexa,hept,octa={},{},{},{},{},{}
	# s = (tri, sq, pent, hexa, hept, octa)
	s = (octa, hept, hexa, pent, sq, tri)
	for num in range(1000,9999):
		if (is_triangular(num)):
			add(s[5], num)
		if (is_square(num)):
			add(s[4], num)
		if (is_pentagonal(num)):
			add(s[3], num)
		if (is_hexagonal(num)):
			add(s[2], num)
		if (is_heptagonal(num)):
			add(s[1], num)
		if (is_octagonal(num)):
			add(s[0], num)
	exclude = [0]*6
	for fig in range(0, len(s)):
		exclude[fig] = 1
		for k,v in s[fig].iteritems():
			for vv in v:
				path = []
				if (getcycle(s, vv % 100, exclude, 1) and (path[0] % 100 == k)):
					path.append(vv)
					path.reverse()
					print count
					print sum(path)
		exclude[fig] = 0
