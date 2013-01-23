
def is_square(n):
	n = n ** 0.5
	return int(n) == n

def sqrt(n):
	return int(n ** 0.5)

def is_pentagonal(x):
	y = 24*x + 1
	if (is_square(y) and (0 == (sqrt(y) + 1) % 6)):
		return 1
	return 0

def is_hexagonal(x):
	y = 8*x + 1
	if (is_square(y) and (0 == (sqrt(y) + 1) % 4)):
		return 1
	return 0

# TODO
# Actually, it makes more sense to increment the hexagonal numbers and find the first
# one that is pentagonal. This is because every hexagonal number is a triangular one too
# This way, you need to check only if a given number is_pentagonal

next_t = 40755
i = 286
while (1):
	next_t = next_t + i
	if (is_pentagonal(next_t) and is_hexagonal(next_t)):
		print i, next_t
		y = 24*next_t + 1
		z = (sqrt(y) + 1) / 6
		print z, z*(3*z - 1)/2
		y = 8*next_t + 1
		z = (sqrt(y) + 1) / 4
		print z, z*(2*z - 1)
		break
	i = i + 1


