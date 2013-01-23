
if __name__ == "__main__":
	count = 0
	for i in range(1,10001):
		lychrel = 0
		num = i
		for j in range (1, 51):
			ri = int(str(num)[::-1])
			new_i = num + ri
			if (str(new_i) == str(new_i)[::-1]):
				lychrel = 1
				break
			num = new_i
		if (lychrel == 0):
			count = count + 1
	print count

