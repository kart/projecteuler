def sqrt(n):
	return int(round(n ** 0.5))

def is_pandigital(n):
	digits = [0] * 10
	l = 0
	while (n != 0):
		r = n % 10
		if (r == 0):
		 	return 0
		if (digits[r]):
			return 0
		digits[r] = 1
		n = n / 10
		l += 1
	return 1

if __name__ == "__main__":
	ans = 0
	for i in range(1234,9876):
		if i % 10 != 0 and not is_pandigital(i):
			continue
		for j in range(2, sqrt(i) + 1):
			if i % j == 0:
				s = str(j) + str(i / j) + str(i)
				if len(s) == 9 and is_pandigital(int(s)):
					ans += i
					break
	print ans
