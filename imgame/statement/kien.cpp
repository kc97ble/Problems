#include <stdio.h>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef pair<int, int> ii;
typedef pair<ii, ii> quad;
#define X first
#define Y second

bool operator >= (ii a, ii b) 
	{ return a.X>=b.X && a.Y>=b.Y; }
bool operator >= (quad a, quad b) 
	{ return a.X>=b.X && a.Y>=b.Y; }
ii operator - (ii a, ii b)
	{ return ii(a.X-b.X, a.Y-b.Y); }
quad operator - (quad a, quad b)
	{ return quad(a.X-b.X, a.Y-b.Y); }
ii operator + (ii a, ii b)
	{ return ii(a.X+b.X, a.Y+b.Y); }
quad operator + (quad a, quad b)
	{ return quad(a.X+b.X, a.Y+b.Y); }

const int oo = 0x3c3c3c3c;
int n, m, Time=0;
bool d[31][31][31][31];
int Num[31][31][31][31];
int Low[31][31][31][31];
long Sum[31][31][31][31];
long Max[31][31][31][31];
long F[31][31][31][31];
quad p[51], q[51];
#define of(u) [u.X.X][u.X.Y][u.Y.X][u.Y.Y]
#define about(u) u.X.X, u.X.Y, u.Y.X, u.Y.Y

long c(quad u) {
	int x=0; long P=1;
	for (int i=1; i<=u.X.X; i++) P=P*(++x)/i;
	for (int i=1; i<=u.X.Y; i++) P=P*(++x)/i;
	for (int i=1; i<=u.Y.X; i++) P=P*(++x)/i;
	for (int i=1; i<=u.Y.Y; i++) P=P*(++x)/i;
	return P;
}

stack<quad> st;

bool visit(quad u) {
	Num of(u) = Low of(u)=++Time;
	Sum of(u) = c(u);
	st.push(u);
	
	for (int i=1; i<=m; i++) 
	if (u>=p[i]) { 
		quad v = u-p[i]+q[i];
		if (F of(v))
			Max of(u) = max(Max of(u), F of(v));
		else if (Num of(v)) 
			Low of(u)=min(Low of(u), Num of(v));
		else { 
			bool ok = visit(v);
			Low of(u) = min(Low of(u), Low of(v));
			if (!ok) {
				Max of(u) = max(Max of(u), Max of(v));
				Sum of(u) += Sum of(v);
			} else {
				Max of(u) = max(Max of(u), F of(v));
			}
		}
	}
	if (Num of(u)==Low of(u)) { quad v;
		F of(u) = Sum of(u) + Max of(u);
		do {
			v=st.top(); st.pop();
			Num of(v) = Low of(v) = oo;
			F of(v) = F of(u);
		} while (u!=v);
		return true;
	}
	return false;
}

quad h(char a[]) {
	int c[4]={0,0,0,0};
	for (int i=0; a[i]; i++)
		c[a[i]-'A']++;
	return quad(ii(c[0], c[1]), ii(c[2], c[3]));
}

main(){
	long Max=0; char s[31];
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++) 
		{ scanf("%s", s); p[i]=h(s); }
	for (int i=1; i<=m; i++)
		{ scanf("%s", s); q[i]=h(s); }
	for (int i=0; i<=n; i++)
		for (int j=0; i+j<=n; j++)
		for (int k=0; i+j+k<=n; k++) {
			quad u(ii(i, j), ii(k, n-i-j-k));
			if (Num of(u) == 0) {
				visit(u);
				Max = max(Max, F of (u));
			}
		}
	cout << Max << endl;
}
