import random

random.seed(17121997)

def randrange(l, r, x = 0):
    res = random.randrange(l, r)
    for i in xrange(x):
        res = max(res, random.randrange(l, r))
    for i in xrange(-x):
        res = min(res, random.randrange(l, r))
    return res

for test in xrange(1, 21):
    limit1 = max(5, int(10 ** (test / (20 / 5.0)) + 1))
    limit2 = max(5, int(10 ** (test / (20 / 9.0)) + 1))
    n = randrange(1, limit1, test - 1)
    a = [randrange(0, limit2) for x in xrange(n)]
    s = [0] * (n + 1)
    for i in xrange(len(a)):
        s[i + 1] = s[i] ^ a[i]
    m = randrange(1, limit1, test - 1)
    queries = []
    for i in xrange(m):
        l = randrange(0, n)
        r = randrange(l, n)
        queries.append((l, r))
    with open("%02d.in" % test, "w") as f:
        print >> f, n, m
        print >> f, " ".join(map(str, a))
        print >> f, "\n".join("%d %d" % (x[0] + 1, x[1] + 1) for x in queries)
    with open("%02d.a" % test, "w") as f:
        print >> f, "\n".join("%d" % (s[x[1] + 1] ^ s[x[0]]) for x in queries)

