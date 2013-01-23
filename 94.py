# The problem can be rephrased as find 'a' and 'H' satisfying ((a +/- 1) / 2)^2 + H^2 = a^2
# Expanding and reducing and multiplying by 3 on both sides of the equation gives two equations
# 	--> (3a - 1)^2 - 12 * H^2 = 4		-- (1)
#	--> (3a + 1)^2 - 12 * H^2 = 4		-- (2)
# Dividing both sides by 4, we get 
# 	--> ((3a - 1) / 2)^2 - 3 * H^2 = 1	-- (3)
# 	--> ((3a + 1) / 2)^2 - 3 * H^2 = 1	-- (4)
# So, we have our classic Pell's equation in the unit form.

def pythogorean(c, a, b): return c * c == a * a + b * b

def valid_triangle(a, b, c):
	return (a + b) > c and (b + c) > a and (c + a) > b

def verify(a, h):
	if ((a - 1) % 2 == 0 and pythogorean(a, (a - 1) / 2, h)) and valid_triangle(a, (a - 1) / 2, h):
		print a, (a - 1) / 2, h
		return 2 * a + (a - 1)
	elif ((a + 1) % 2 == 0 and pythogorean(a, (a + 1) / 2, h)) and valid_triangle(a, (a + 1) / 2, h):
		print a, (a + 1) / 2, h
		return 2 * a + (a + 1)
	else:
		return 0

def perimeter(p, q):
	# verify if a given solution to x^2 - 3*y^2 = 1 satisfies a proper triangle and if so, return the perimter
	# Here x = ((3a - 1) / 2), y = H
	if ((2 * p + 1) % 3 == 0):
		# p, q satsifies (3)
		a = (2 * p + 1) / 3
		return verify(a, q)
	elif ((2 * p - 1) % 3 == 0):
		# p, q satisfies (4)
		a = (2 * p - 1) / 3
		return verify(a, q)
	else:
		return 0

ans = 0			# First solution (from the problem statement)
LIMIT = 1000000000
a = 1
term = 1
hprev, hprevprev = 1, 0
kprev, kprevprev = 0, 1
# Since D in this case is 3, the continued fraction is [1; 1, 2] and so the period is 2.
while 1:
	p = a * hprev + hprevprev
	q = a * kprev + kprevprev
	term += 1
	if (term % 2 == 0): a = 1
	else: 
		a = 2
		x = perimeter(p, q)
		if (x > LIMIT):
			break
		ans += x
	hprevprev, hprev = hprev, p
	kprevprev, kprev = kprev, q

print ans
