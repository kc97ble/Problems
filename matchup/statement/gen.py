import re
FILE = open("matchup.txt","r")
it = 0
for line in FILE:
  data = line.split()
  if len(data) < 1:
    continue

  it += 1
  beta = data[0].split(',')
  us = [int(x) for x in beta]
  gamma = data[1].split(',')
  them = [int(x) for x in gamma]
  answer = int(data[2])
  n = len(us)

  fa = open(str(it) + ".in","w")
  fa.write('%d\n' % n)
  for element in us:
    fa.write('%d ' % element)
  fa.write('\n')
  for element in them:
    fa.write('%d ' % element)
  fa.write('\n')

  fb = open(str(it) + ".out","w")
  fb.write('%d\n' % answer)
