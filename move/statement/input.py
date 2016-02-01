from random import randrange
import os

def make(m, x, File1, File2):
	n=m+randrange(-4, 4);
	print File1, File2, m, n
	with open(File1, "w") as f:
		print >>f, m, n
		for i in range(m):
			print >>f, " ".join([str(randrange(-x, x)) for j in range(n)])
	os.system('./kien < {} > {}'.format(File1, File2))
			

for i in range(20):
	make(int(i*i*1.3+5), int(i*i*i*1.4+10), str(i)+".in", str(i)+".ans")
