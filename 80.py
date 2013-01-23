from math import sqrt

# The below function is an evaluation of current partial denominator to arrive at the next partial denominator
# N, b, d represents (sqrt(N) + b) / d; approx is the floor(sqrt(N))
# The function returns the next set of b, d to the caller and the nth term of the continued fraction
def next(N, b, d, approx):
	den = N - b * b
	a = (d * (approx - b)) / den	# This is the next term
	d = den / d
	b = (-1 * b) - (d * a)
	return a, b, d

# Compute Square root of N using continued fractions. I used the number of iterations before I stop at 175.

MAX = 100
MAX_ITER = 175
ans = 0
for i in range(2, MAX + 1):
	approx = int(sqrt(i))
	if approx * approx == i: continue
	a, b, d = approx, -1 * approx, 1
	hprev, hprevprev = 1, 0
	kprev, kprevprev = 0, 1
	period = 0
	first_a = -1
	count = 0
	while count < MAX_ITER:
		num = a * hprev + hprevprev
		den = a * kprev + kprevprev
		if d == 1 and period != 0: a = first_a
		a, b, d = next(i, b, d, approx)
		if (first_a == -1): first_a = a
		period += 1
		hprevprev, hprev = hprev, num
		kprevprev, kprev = kprev, den
		count += 1
	rem = num % den
	count = 0
	digits = [0] * 110
	s = num / den
	while count < 99:
		if rem < den:
			rem *= 10
		while rem < den:
			count += 1
			rem *= 10
		digits[count] = rem / den
		rem = rem % den
		count += 1
	ans += (s + sum(digits[0:99]))
print ans
