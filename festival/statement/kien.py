from fractions import gcd

def get_line(Type):
	return map(Type, raw_input().strip().split())

def main(Test):
	a = get_line(int)
	n = a.pop(0)
	M = 0
	for x in a:
		for y in a:
			if x>y:
				M = gcd(M, x-y)

	print "Case #%d: %d" % (i+1, (M-a[0])%M)

n = int(raw_input().strip())
for i in range(n):
	main(i)

