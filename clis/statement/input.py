import random
import os

def randchar():
	return chr(random.randrange(65, 65+26))

def make(n, File1, File2):
	print File1, File2, n
	with open(File1, "w") as f:
		print >>f, "".join([randchar() for i in range(n)])
	os.system('./kien < {} > {}'.format(File1, File2))
			

for i in range(25):
	make(i*8+8, str(i)+".in", str(i)+".ans")
