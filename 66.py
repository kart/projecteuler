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

# Pell's equation : Solution for x^2 - Dy^2 = 1 is based on the period of the continued fraction of sqrt(D)

MAX = 1000
maxx = -1
maxd = -1
for i in range(2, MAX + 1):
	approx = int(sqrt(i))
	if approx * approx == i: continue
	a, b, d = approx, -1 * approx, 1
	hprev, hprevprev = 1, 0
	kprev, kprevprev = 0, 1
	period = 0
	done = 0
	first_a = -1
	while 1:
		num = a * hprev + hprevprev
		den = a * kprev + kprevprev
		if d == 1 and period != 0:
			if period % 2 == 0: break
			if not done:
				a = first_a
				done = 1
			else: break
		a, b, d = next(i, b, d, approx)
		if (first_a == -1): first_a = a
		period += 1
		hprevprev, hprev = hprev, num
		kprevprev, kprev = kprev, den
	if num > maxx:
		maxx = hprev
		maxd = i
print maxd, maxx
