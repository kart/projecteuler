f = open('cipher1.txt', 'r')
for line in f:
	x = line.strip().split(',')
for a in range(97, 123):
	for b in range(97, 123):
		for c in range(97, 123):
			cipher = [a, b, c]
			good = 1
			tot = 0
			s = ''
			for i in xrange(0, len(x), 3):
				c1, c2, c3 = 0, 0, 0
				c1 = (cipher[0] ^ int(x[i]))
				if c1 < 32 or c1 > 122: good = 0
				if i + 1 < len(x):
					c2 = (cipher[1] ^ int(x[i + 1]))
					if c2 < 32 or c2 > 122: good = 0
				if i + 2 < len(x): 
					c3 = (cipher[2] ^ int(x[i + 2]))
					if c3 < 32 or c3 > 122: good = 0
				if not good:
					break
				tot += c1 + c2 + c3
				s = s + chr(c3) + chr(c2) + chr(c3)
			if good:
				print s, cipher, tot

			
