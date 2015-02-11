import re
FILE = open("encoding.txt","r")
it = 0
for line in FILE:
  data = line.split()
  if len(data) < 1:
    continue
  it += 1
  fa = open(str(it) + ".in","w")
  fa.write(data[0])
  fb = open(str(it) + ".out","w")
  fb.write(data[1])

