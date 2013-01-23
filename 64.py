from math import sqrt

# The below function is an evaluation of current partial denominator to arrive at the next partial denominator
# N, b, d represents (sqrt(N) + b) / d; approx is the floor(sqrt(N))
# The function returns the next set of b, d to the caller
def next(N, b, d, approx):
	den = N - b * b
	a = (d * (approx - b)) / den	# This is the next term
	d = den / d
	b = (-1 * b) - (d * a)
	return b, d

MAX = 10000
count = 0
for i in range(2, MAX + 1):
	approx = int(sqrt(i))
	if approx * approx == i: continue
	b, d = -1 * approx, 1
	period = 0
	while d != 1 or period == 0:
		b, d = next(i, b, d, approx)
		period += 1
	if period % 2 == 1: count += 1
print count
