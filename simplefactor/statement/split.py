#!/usr/bin/env python

count = 0

with open('in.txt', 'r') as f:
	for s in f:
		with open('%02d.in' % count, 'w') as g:
			print >>g, s
		count += 1

count = 0

with open('out.txt', 'r') as f:
	for s in f:
		with open('%02d.ans' % count, 'w') as g:
			print >>g, s
		count += 1
