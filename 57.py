# Uses recurrence relation for computing the ith continued fraction. See wiki - http://en.wikipedia.org/wiki/Continued_fraction
#
import math

def digits(n): return int(math.ceil(math.log10(n)))

h_prev = 1
h_prev_prev = 0
k_prev = 0
k_prev_prev = 1
count = 0
for i in range(0, 1001):
	if i == 0: a = 1
	else: a = 2
	num = a * h_prev + h_prev_prev
	den = a * k_prev + k_prev_prev
	if digits(num) > digits(den): count+=1
	h = a * h_prev + h_prev_prev
	k = a * k_prev + k_prev_prev
	h_prev_prev = h_prev
	h_prev = h
	k_prev_prev = k_prev
	k_prev = k

print count	
