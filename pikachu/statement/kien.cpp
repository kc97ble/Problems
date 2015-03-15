#include <stdio.h>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
typedef set<ii>::iterator itsii;
#define X first
#define Y second

#define N 100005
int n, k, a[N];

int force(int l, int r){
	int Sum = 0;
	vector<int> b(a+l, a+r+1);
	sort(b.begin(), b.end());
	f0(i,b.size()) Sum += abs(b[i] - b[(b.size()-1)/2]);
	return Sum;
}

int force(){
	int Min = 0x3c3c3c3c;
	for (int i=k; i<=n; i++)
	Min = min(Min, force(i-k+1, i));
	return Min;
}

main(){
	freopen("pikachu.in", "r", stdin);
	freopen("pikachu.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	f1(i,n) scanf("%d", &a[i]);
//	f1(i,n) printf("%d ", a[i]=rand()%100); printf("\n");
	if (k==1) { cout << 0 << endl; return 0; }
	
	long Less=0, More=0;
	
	set<ii> Set;
	f1(i,k) { Set.insert(ii(a[i], i)); More+=a[i]; }
	int x=0; itsii it=Set.begin(); More-=it->X;
	
	while (x<(k-1)/2) { Less+=it->X; x++, it++; More-=it->X; }
	while (x>(k-1)/2) { More+=it->X; x--, it--; Less-=it->X; }
//	printf("%d %lld %lld %lld\n", it->X, Less, More, More-Less-(k&1 ? 0 : it->X));
	long Min = More-Less-(k&1 ? 0 : it->X);
	
	for (int i=k+1; i<=n; i++) {
		if (a[i]<it->X) { Less+=a[i]; x++; } else More+=a[i];
		Set.insert(ii(a[i], i));
		
		itsii jt=Set.lower_bound(ii(a[i-k], 0));
		if (*jt <= *it) { Less+=it->X; x++, it++; More-=it->X; } // now jt!=it
		if (*jt<*it) { x--; Less-=jt->X; } else More-=jt->X;
		Set.erase(jt);
		
		while (x<(k-1)/2) { Less+=it->X; x++, it++; More-=it->X; }
		while (x>(k-1)/2) { More+=it->X; x--, it--; Less-=it->X; }
//		printf("%d %lld %lld %lld\n", it->X, Less, More, More-Less-(k&1 ? 0 : it->X));
		Min = min(Min, More-Less-(k&1 ? 0 : it->X));
	}
	cout << Min << endl;
//	cout << force() << endl;
}
