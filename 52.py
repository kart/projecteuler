ndigit_start = [10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000]

def solve(n):
	ident = ''.join(sorted(str(n)))
	count = 1
	for i in range(2, 7):
		if ident == ''.join(sorted(str(i * n))): count+=1
		else: break
	return count == 6

for i in range(0, 7):
	for j in range(ndigit_start[i], ndigit_start[i + 1]):
		if 6 * j >= ndigit_start[i + 1]: break
		else:
			if solve(j):
				print j, 2*j, 3*j, 4*j, 5*j, 6*j
				exit(0)
