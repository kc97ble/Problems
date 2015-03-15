import re
FILE = open("pub1.txt","r")
it = 0
for line in FILE:
  data = line.split()
  if len(data) < 1:
    continue
  it += 1
  points = [int(x) for x in data[0].split(',')]
  tokens = int(data[1])
  bonus = [int(x) for x in data[2].split(',')]
  answer = int(data[3])

  fa = open(str(it) + ".in","w")
  fa.write('%d\n' % len(points))
  for element in points:
    fa.write('%d ' % element)
  fa.write('\n')
  fa.write('%d\n' % tokens)
  for element in bonus:
    fa.write('%d ' % element)
  fa.write('\n')

  fb = open(str(it) + ".out","w")
  fb.write('%d\n' % answer)
