import random
from sets import Set
file_name = 'treasure'
random.seed(123456791)

def gen(N, K, f):
    element = Set()
    used = Set()
    for t in xrange(K):
        k = 0
        while True:
            k = random.randint(0, 2*N-2)
            if not k in used:
                used.add(k)
                break;
        i = random.randint(0, min(k, N-1) );
        j = k - i;
        element.add( (i,j) )
    
    f.write('%d\n' % N)
    for i in xrange(N):
        for j in xrange(N):
            if (i,j) in element:
                f.write('1 ')
            else: 
                f.write('0 ')
        f.write('\n')
        
def genCase(start, end, min_n, max_n, dd=False):
    for i in xrange(start, end+1):
        f = open( file_name+'%02d.inp' % i, 'w')
        N = random.randint(min_n, max_n);
        if not dd:
            K = random.randint(N/2, N + N/2);
        else:
            K = N*N - 123456;
        gen( N, K, f );
        f.close()
        

genCase(1, 6, 1, 50)
genCase(7, 12, 80, 100)
genCase(13, 18, 500, 1000)
genCase(19, 20, 800, 1000, True)

        
        
    
    
