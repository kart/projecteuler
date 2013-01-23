def is_pandigital(n):	# true if n is 1 through 9 pandigital
	a = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	while n:
		x = n % 10
		n = n / 10
		if (a[x] or x == 0):
			return 0
		a[x] = a[x] + 1
	return 1

if __name__ == "__main__":
	maxi = 918273645
	for j in range(9000,10000):
		s = ""
		for k in range(1, 5):
			s = s + str(j * k)
			cand = int(s)
			if (len(s) == 9 and is_pandigital(cand)):
				if (maxi < cand):
					maxi = cand
	print maxi
			
