FILE = open('barons.txt','r')
it = 0
for line in FILE:
  it += 1
  allInput = line.split()
  dx = [int(x) for x in allInput[0].split(',')]
  dy = [int(x) for x in allInput[1].split(',')]  
  results = int(allInput[2])

  fa = open(str(it) + '.in','w')
  fa.write('%d\n' % len(dx))
  for i in range(len(dx)):
    fa.write('%d %d\n' % (dx[i], dy[i]))
  fb = open(str(it) + '.out','w')
  fb.write('%d\n' % results)
