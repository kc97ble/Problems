FILE = open('cchange.txt','r')
it = 0
for line in FILE:
  it += 1
  allInput = line.split()
  coinValue = [int(x) for x in allInput[0].split(',')]
  noteValue = int(allInput[1])
  results = allInput[2]
  
  fa = open(str(it) + '.in','w')
  fa.write('%d %d\n' % (len(coinValue), noteValue)
