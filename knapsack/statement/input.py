from random import randrange, seed
import os

def make(n, M, MaxY, File1, File2):
	MaxX = randrange(max(1, M/n), M+1)
	print File1, File2, n, M, MaxX, MaxY
	
	with open(File1, "w") as f:
		print >>f, n, M
		ListX = [randrange(MaxX)+1 for i in range(n)]
		ListY = [randrange(MaxY)+1 for i in range(n)]
		for i in range(n):
			print >>f, "{} {}".format(ListX[i], ListY[i])
	os.system('./kien < {} > {}'.format(File1, File2))
	
seed(0)
for i in range(25):
	make(int(i*i*8.6)+10, i*200+50, i*i*17+10, str(i)+".in", str(i)+".ans")
