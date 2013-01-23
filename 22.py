if __name__ == "__main__":
	lis = []
	f = open('22.in', 'r')
	for line in f:
		s = line[0:len(line) - 1]
		lis.append(s)
	f.close()
	score = 0
	for word in lis:
		indx = lis.index(word) + 1
		s = 0
		for c in word:
			s = s + (ord(c) - ord('A') + 1)
		score = score + (s * indx)
	print score
