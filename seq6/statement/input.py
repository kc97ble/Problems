from random import randrange, seed
import os

def make(n, z, File1, File2):
	M = randrange(1<<min(n, 50))%100000 + 1
	print File1, File2, n, M, z
	
	with open(File1, "w") as f:
		print >>f, n, M
		List = [randrange(z) for i in range(n)]
		print >>f, " ".join(map(str, List))
	os.system('./kien < {} > {}'.format(File1, File2))
	
seed(0)
for i in range(25):
	make(int(i*i*0.16)+4, i**6*5+10, str(i)+".in", str(i)+".ans")
