cnt = 0
with open("in.txt") as inf:
    for ans in open("out.txt"):
        cnt += 1
        n, m, k = map(int, inf.readline().strip().split())
        with open("%02d" % cnt, "w") as inf2:
            inf2.write("%d %d %d\n" % (n, m, k))
            for x in xrange(n):
                inf2.write(inf.readline())
        with open("%02d.a" % cnt, "w") as ans2:
            ans2.write(ans)