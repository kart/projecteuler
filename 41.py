def is_pandigital(n):
	l = len(str(n))
	digits = [0] * (l + 1)
	while (n != 0):
		r = n % 10
		if (r == 0 or r > l):
			return 0
		if (digits[r]):
			return 0
		digits[r] = 1
		n = n / 10
	return 1

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

if __name__ == "__main__":
	ans = 0
	for i in range(7654321, 1234566, -1):
		if is_pandigital(i) and is_prime(i):
			print i
			break
