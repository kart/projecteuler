def gcd(a, b):
	if (b == 0):
		return a
	return gcd(b,a%b)

if __name__ == "__main__":
	for y in range(1,10):
		for x in range(1,10):
			for z in range(1,10):
				numer = 10*x + y
				denom = 10*y + z
				if (numer < denom):
					g1 = gcd(numer,denom)
					g2 = gcd(x,z)
					if (numer/g1 == x/g2 and denom/g1 == z/g2):
						print numer,"/",denom
	
