from random import randrange
import os

def make(n, z, File1, File2):
	k = randrange(1, min(n, 1000))
	print File1, File2, n, k, z
	with open(File1, "w") as f:
		print >>f, n, k
		List = [randrange(1, z) for i in range(n)]
		print >>f, " ".join(map(str, List))
	os.system('./kien < {} > {}'.format(File1, File2))

for i in range(25):
	make(i*i*11+5, i*i+10, str(i)+".in", str(i)+".ans")
