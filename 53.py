import math

# The given problem can be represented as the following equation -
# 
# n!/(r!(n-r)!) >= 1000000 ; 1 <= n,r <= 100
# 
# Taking log on both sides immediately simplifies the problem and removes all the overhead of doing computations
# log10(n!) - (log10(r!) + log10((n-r)!)) >= 6
# 
# This way all you need to do is compute the log(n!) for 1 <= n <= 100 once and run a double loop to find the answer

if __name__ == "__main__":
	f_log = [0, 0]
	for i in range(2,101):
		val = f_log[i - 1] + math.log10(i)
		f_log.append(val)
	count = 0
	for n in range(23,101):
		for r in range(2,n):
			if (6.0 <= f_log[n] - (f_log[r] + f_log[n - r])):
				count = count + 1
	print count
		
