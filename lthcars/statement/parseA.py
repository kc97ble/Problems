ans = open('out.txt').readlines()
inp = open('in.txt')
cnt = 0
for x in ans:
    cnt += 1
    n = inp.readline()
    with open('%02d' % cnt, 'w') as finp:
        finp.write(n)
        for i in xrange(int(n)):
            finp.write(inp.readline())
    with open('%02d.a' % cnt, 'w') as fout:
        fout.write(x)
