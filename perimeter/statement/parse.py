cnt = 0
with open("in.txt") as inf:
    for ans in open("out.txt"):
        cnt += 1
        n = int(inf.readline().strip())
        with open("%02d" % cnt, "w") as inf2:
            inf2.write("%d\n" % n)
            for x in xrange(n):
                inf2.write(inf.readline())
        with open("%02d.a" % cnt, "w") as ans2:
            ans2.write(ans)
