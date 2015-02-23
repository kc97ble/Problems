FILE = open('hamilton.txt','r')
it = 0
for line in FILE:
  it += 1
  allInput = line.split()
  board = allInput[0].split(',')
  results = int(allInput[1])

  fa = open(str(it) + '.in','w')
  fa.write('%d\n' % len(board))
  for element in board:
    fa.write(element)
    fa.write('\n')
  fb = open(str(it) + '.out','w')
  fb.write('%d\n' % results)
