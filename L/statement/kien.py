def power(a, k, p):
	P=1
	while k!=0:
		if k&1: P=P*a%p
		a=a*a%p; k//=2
	return P

Token = raw_input().split()
m, n, p = map(int, Token)
P=1
for i in range(m*m-n*n):
	P=P*(i+1)%p
Invert = list(power(i, p-2, p) for i in range(m+m+1))
Length = [m]*(m-n)+[m-n]*n
for i in range(len(Length)):
	for j in range(Length[i]):
		Hook = Length[i]-j+Length[j]-i-1
		P=P*Invert[Hook]%p
print P

