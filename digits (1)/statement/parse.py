import re

FILE = open("digits.txt","r")
it = 0
for line in FILE:
  it += 1  
  data = line.split()
  fa = open(str(it) + ".in","w")

  j = 0
  while j < len(data) - 1:
    fa.write(data[j])
    fa.write('\n')
    j += 1
  fb = open(str(it) + ".out","w")
  fb.write(data[j])
