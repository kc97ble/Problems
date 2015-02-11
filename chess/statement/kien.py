n = int(input())
if n%4==0 or n%4==1:
	P = 1
	for i in range(n//4+1, n//2+1):
		P *= i
	print(P)
else:
	print(0)

