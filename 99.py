import math
if __name__ == "__main__":
	maxi = -1.0
	save = []
	f = open("99.in", 'r')
	for line in f:
		a = line.strip()
		a = a.split(",")
		lval = 1.0 * int(a[1]) * math.log10(int(a[0]))
		if (lval > maxi):
			maxi = lval
			save = a
	print maxi, save
