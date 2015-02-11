fi = open("cake.txt","r")
test = 0
for line in fi:
  test += 1
  d1 = line.split()
  d2 = d1[0].split(',')
  print "INDEX ", test
  print d1, d2
  ga = str(test) + ".in"
  fa = open(ga,"w")
  for i in range(len(d2)):
    fa.write(d2[i])
    if i == 1 or i == 8:
      fa.write('\n')
    else:
      fa.write(' ')
  gb = str(test) + ".out"
  fb = open(gb,"w")
  fb.write(d1[1])
