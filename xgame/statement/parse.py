FILE = open('xgame.txt','r')
it = 0
for line in FILE:
  it += 1
  allInput = line.split()
  inputParam = allInput[0]
  outputParam = allInput[1]
  
  fa = open(str(it) + '.in','w')
  for i in range(1,len(inputParam) - 1):
    fa.write(inputParam[i])
  fb = open(str(it) + '.out','w')
  fb.write(outputParam)
