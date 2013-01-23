# Uses recurrence relation for computing the ith continued fraction. See wiki - http://en.wikipedia.org/wiki/Continued_fraction
#
import math
def sumofd(n):
	s = 0
	while n != 0:
		s += n % 10
		n = n / 10
	return s

h_prev = 1
h_prev_prev = 0
k_prev = 0
k_prev_prev = 1
cycle = 1
for i in range(0, 101):
	if i == 0:
		a = 2
	elif i % 3 == 1 or i % 3 == 0: a = 1
	else:
		a = 2 * cycle
		cycle += 1
	num = a * h_prev + h_prev_prev
	den = a * k_prev + k_prev_prev
	print "sum of numerator digits for the ", i + 1, "th term = ", sumofd(num)
	h = a * h_prev + h_prev_prev
	k = a * k_prev + k_prev_prev
	h_prev_prev = h_prev
	h_prev = h
	k_prev_prev = k_prev
	k_prev = k
