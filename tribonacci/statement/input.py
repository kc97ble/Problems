import random
import os

def make(t, x, File1, File2):
	print File1, File2
	with open(File1, "w") as f:
		for i in range(t):
			print >>f, 1 << random.randrange(0, x)
	os.system('./kien < {} > {}'.format(File1, File2))
			

for i in range(25):
	make(i*4+4, i+5, str(i)+".in", str(i)+".ans")
