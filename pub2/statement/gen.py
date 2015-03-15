import re
FILE = open("pub2.txt","r")
it = 0
for line in FILE:
  data = line.split()
  if len(data) < 1:
    continue
  it += 1
  nc = [int(x) for x in data[0].split(',')]
  lp = [int(x) for x in data[1].split(',')]
  lb = [int(x) for x in data[2].split(',')]
  answer = int(data[3])

  fa = open(str(it) + ".in","w")
  fa.write('%d %d\n' % (nc[0], nc[1]))
  fa.write('%d\n' % len(lp))
  for element in lp:
    fa.write('%d ' % element)
  fa.write('\n')
  fa.write('%d\n' % len(lb))
  for element in lb:
    fa.write('%d ' % element)

  fb = open(str(it) + ".out","w")
  fb.write('%d ' % answer)

