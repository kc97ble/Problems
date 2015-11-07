cnt = 0
with open("in.txt") as inf:
	inf.readline()
	for ans in open("out.txt"):
		cnt += 1
		print "%02d %02d.a" % (cnt, cnt)
		n = int(inf.readline().strip())
		with open("%02d" % cnt, "w") as inf2:
			inf2.write("%d\n" % n)
			for x in xrange(n+1):
				inf2.write(inf.readline())
		with open("%02d.a" % cnt, "w") as ans2:
			ans2.write(ans)
