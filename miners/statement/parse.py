FILE = open('miners.txt','r')
it = 0
for line in FILE:
  it += 1
  allInput = line.split()
  board = allInput[0].split(',')
  distance = int(allInput[1])
  results = int(allInput[2])

  fa = open(str(it) + '.in','w')
  fa.write('%d %d %d\n' % (len(board), len(board[0]), distance))
  for element in board:
    fa.write(element)
    fa.write('\n')
  fb = open(str(it) + '.out','w')
  fb.write('%d\n' % results)
