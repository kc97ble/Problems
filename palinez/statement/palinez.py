from random import *

def generate(n, fn1, fn2):
	m = min(randint(1, n*n/3+5), 5000)
	th = random()
	s = "".join(['0' if random()<th else '1' for i in range(n)])
	List=[]
	print n, m, th, fn1, fn2
	with open(fn1, 'w') as f:
		print >>f, s
		print >>f, m
		for i in range(m):
			M=randint(1, n)
			L=randint(1, M)
			R=randint(M, n)
			print >>f, L, R
			List.append(s[L-1:R]==s[L-1:R][::-1])
	with open(fn2, 'w') as f:
		for x in List:
			print >>f, "YES" if x else "NO"

seed(0)
for i in range(50):
	generate(i*i*2+5, "%d.in" % i, "%d.ans" % i);
