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
    z = randrange(0, limit2)
    a = a + a + [z]
    random.shuffle(a)
    
    with open("%02d.in" % test, "w") as f:
        print >> f, n*2+1
        print >> f, " ".join(map(str, a))
    with open("%02d.a" % test, "w") as f:
        print >> f, z

