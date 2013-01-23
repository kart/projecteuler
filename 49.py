def is_prime(n):
	if (n == 1):
		return 0
	if (n < 4):
		return 1
	if (n % 2 == 0):
		return 0
	if (n < 9):
		return 1
	if (n % 3 == 0):
		return 0
	i = 5
	while (i * i < n):
		if n % i == 0:
			return 0
		if n % (i + 2) == 0:
			return 0
		i += 6
	return 1

def identity(n):
	return int(''.join(sorted(str(n))))
		
if __name__ == "__main__":
	ans = 0
	d = {}
	for i in range(1000, 10000):
		if is_prime(i):
			ident = identity(i)
			if ident in d:
				d[ident].append(i)
			else:
				d[ident] = [i, ]
	for k,v in d.iteritems():
		for i in range(0, len(v)):
			for j in range(i + 1, len(v)):
				for k in range(j + 1, len(v)):
					if v[k] - v[j] == v[j] - v[i]:
						print v[i], v[j], v[k]
	
