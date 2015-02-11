FILE = open('cchange.txt','r')
it = 0
for line in FILE:
  it += 1
  allInput = line.split()
  coinStr = allInput[0].split(',')
  coinValue = [int(x) for x in coinStr]
  noteValue = int(allInput[1])
  results = int(allInput[2])

  fa = open(str(it) + '.in','w')
  fa.write('%d %d\n' % (len(coinValue), noteValue))
  for element in coinValue:
    fa.write('%d ' % element)
  fb = open(str(it) + '.out','w')
  fb.write('%d\n' % results)
