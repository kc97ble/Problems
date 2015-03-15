#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define for_each(it, a) for (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
const int N = 300005;
int n, x[N], y[N];
vector<int> a[N];

int Count[4*N], Inc[4*N];
long Sum[4*N];

struct node {
	int ll, rr, id;
	node (int L, int R, int U)
		{ ll=L; rr=R; id=U; access(); }
	node left()
		{ return node(ll, (ll+rr)/2, id*2); }
	node right()
		{ return node((ll+rr)/2+1, rr, id*2+1); }
	
	void access() {
		if (Inc[id]==0) return;
		Sum[id]+=1LL*Count[id]*Inc[id];
		if (ll!=rr) {
			Inc[id*2] += Inc[id];
			Inc[id*2+1] += Inc[id];
		}
		Inc[id]=0;
	}
	
	void inc_range(int L, int R) {
		//if (id==1) printf("inc_range(%d, %d)\n", L, R);
		if (L>rr || ll>R || L>R) return ;
		if (L<=ll && rr<=R) { Inc[id]++; access(); return; }
		left().inc_range(L, R);
		right().inc_range(L, R);
		Sum[id] = Sum[id*2] + Sum[id*2+1];
	}
	
	long sum_range(int L, int R) {
		if (L>rr || ll>R || L>R) return 0;
		if (L<=ll && rr<=R) return Sum[id];
		long Sum1 = left().sum_range(L, R);
		long Sum2 = right().sum_range(L, R);
		//if (id==1) printf("sum_range(%d, %d) = %lld\n", L, R, Sum1+Sum2);
		return Sum1 + Sum2;
	}
	
	void insert(int U, int X) {
		//if (id==1) printf("insert(%d, %d)\n", U, X);
		if (U>rr || ll>U) return ;
		if (ll==rr) { Count[id]+=X; return ; }
		left().insert(U, X);
		right().insert(U, X);
		Count[id] = Count[id*2] + Count[id*2+1];
	}
};

void compress(int a[], int n) {
	vector<int> K(a+1, a+n+1);
	sort(K.begin(), K.end());
	for (int i=1; i<=n; i++)
	a[i] = lower_bound(K.begin(), K.end(), a[i]) - K.begin() + 1;
}

main() {
	cin >> n;
	
	int xz, xa, xb, xm;
	cin >> xz >> xa >> xb >> xm;
	x[1]=xz; for (int i=2; i<=n; i++) x[i]=(1LL*x[i-1]*xa+xb)%xm;
	
	int yz, ya, yb, ym;
	cin >> yz >> ya >> yb >> ym;
	y[1]=yz; for (int i=2; i<=n; i++) y[i]=(1LL*y[i-1]*ya+yb)%ym;
	
	compress(x, n);
	compress(y, n);	
	for (int i=1; i<=n; i++)
	a[x[i]].push_back(y[i]);
	
	//for (int i=1; i<=n; i++)
	//printf("(%d, %d)\n", x[i], y[i]);
	
	long Sum = 0;
	for (int x=n; x>=1; x--) {
		sort(a[x].rbegin(), a[x].rend());
		for_each(it, a[x]) if (int y=*it) {
			Sum += node(1, n, 1).sum_range(y+1, n);
		}
		for_each(it, a[x]) if (int y=*it) {
			node(1, n, 1).inc_range(1, y-1);
			node(1, n, 1).insert(y, 1);
		}
		//printf("Sum = %lld\n", Sum);
	}
	cout << Sum << endl;
}
