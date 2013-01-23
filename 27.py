def seive(n):
	p = 2
	primes = {}
	a = [1] * (n + 1)
	while p * p <= n:
		if a[p]:
			for i in range(2 * p, n + 1, p): a[i] = 0
		p += 1
	for i in range(2, n + 1):
		if a[i]: primes[i] = 1
	return primes

def cond(a, b, primes):
	if b not in primes or a % 2 == 0 or 1600 + 40 * a + b not in primes:
		return 0
	return 1

def f(n, a, b):
	return n * n + a * n + b

def solve(a, b, primes, low, high):
	print "Trying (", low, ",", high, ")"
	if f(low, a, b) not in primes:
		return 0, 0
	low += 1
	while low < high:
		mid = (low + high) / 2
		if f(mid, a, b) in primes:
			print "f(", mid, ") is prime"
			new_mid = solve(a, b, primes, low, mid - 1)
			if (new_mid < mid - 1):
				high = new_mid
			else:
				low = mid + 1
		else:
			print "f(", mid, ") is not prime"
			new_mid = solve(a, b, primes, low, mid - 1)
			high = new_mid - 1
	if f(high, a, b) in primes:
		return high
	return low - 1

def verify(a, b, primes, low, high):
	global count
	for i in range(low, high + 1):
		if f(i, a, b) not in primes:
			count += 1
			return i - 1
	return high

primes = seive(50000)
count = 1
nmax = -1
lst = []
for a in range(-1000, 1001):
	for b in range(-1000, 1001):
		if cond(a, b, primes):
			l = verify(a, b, primes, 41, 80)
			if (l > nmax):
				nmax = l
				na = a
				nb = b
print na * nb, count
