import re
FILE = open("bgame1.txt","r")
it = 0
for line in FILE:
  data = line.split()
  if len(data) < 1:
    continue
  it += 1
  inputArg = [int(x) for x in data[0].split(',')]
  fa = open(str(it) + ".in", "w")
  for element in inputArg:
    fa.write('%d ' % element)
  fa.write('\n')
  fb = open(str(it) + ".out","w")
  if len(data) > 1:
    outputArg = [int(x) for x in data[1].split(',')]
    for element in outputArg:
      fb.write('%d ' % element)
    fb.write('\n')
