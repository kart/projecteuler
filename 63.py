import math

count = 0
for ndigit in range(1, 22):
	for i in range(1, 10):
		if ndigit == len(str(i ** ndigit)):
			print i ** ndigit
			count += 1
print count
