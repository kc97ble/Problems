def get_line(T):
	return map(int, raw_input().split())

m, n, p = get_line(int)
Next=range(1,n) + [0]
Prev=[n-1] + range(0,n-1)

x=0
T=[]

for i in range(n):
	Next[Prev[x]]=Next[x]
	Prev[Next[x]]=Prev[x]
	if i%m==m-1:
		T+=[x]
	for j in range(p+1):
		x=Next[x]

print "\n".join(str(x+1) for x in sorted(T))

