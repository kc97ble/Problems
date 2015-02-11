#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
#define each(it, a) (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
#define all(a) a.begin(), a.end()
#define index_of(x, a) (lower_bound(a.begin(), a.end(), x)-a.begin())
typedef pair<int, int> ii;
typedef pair<ii, ii> quad;
#define X first
#define Y second

quad rect(int x, int y, int u, int v)
	{ return quad(ii(x,y),ii(u,v)); }

int m, n;
vector<ii> House; //

long f(int x, int y, int xx, int yy, int k){
	vector<quad> Event;
	for each(it, House) {
		int X=it->X, Y=it->Y;
		quad R = rect(max(X-k, x), max(Y-k, y), min(X+k, xx), min(Y+k, yy));
		if (R.X.X>R.Y.X || R.X.Y>R.Y.Y) continue;
		//printf("Rect: %d, %d, %d, %d\n", R.X.X, R.X.Y, R.Y.X, R.Y.Y);
		Event.push_back(rect(R.X.X, 1, R.X.Y, R.Y.Y));
		Event.push_back(rect(R.Y.X+1, -1, R.X.Y, R.Y.Y));
	}
	sort(all(Event));
	
	vector<int> ListY;
	for each(it, Event) {
		ListY.push_back(it->Y.X);
		ListY.push_back(it->Y.Y+1);
	}
	sort(all(ListY)); 
	ListY.erase(unique(all(ListY)), ListY.end());
	
	long Sum=0, Cur=0, LastX=0;
	vector<int> Count(ListY.size());
	
	for each(it, Event) {
		int y1=index_of(it->Y.X, ListY), y2=index_of(it->Y.Y+1, ListY)-1;
		Sum += Cur*(it->X.X-LastX);
		for (int i=y1; i<=y2; i++) if (Count[i]) Cur -= ListY[i+1] - ListY[i];
		for (int i=y1; i<=y2; i++) Count[i]+=it->X.Y;
		for (int i=y1; i<=y2; i++) if (Count[i]) Cur += ListY[i+1] - ListY[i];
		LastX=it->X.X;
	}
	
	for each(it, House)
	if (x<=it->X && it->X<=xx)
	if (y<=it->Y && it->Y<=yy)
	Sum--;
	
	//printf("f(%d, %d, %d, %d, %d) = %lld\n", x, y, xx, yy, k, Sum);
	return Sum;
}

long g(int x, int y, int xx, int yy, int k){
	return f(x,y,xx,yy,k) - f(x,y,xx,yy,k-1);
}

int Line=0;

void solve(long Index) {
	int R, x, y;
	
	for (int ll=1, rr=max(m,n); R=(ll+rr)/2, ll<rr; )
	if (f(1,1,m,n,R)>=Index) rr=R; else ll=R+1;
	Index -= f(1,1,m,n,R-1);
	//printf("R=%d, Index=%lld\n", R, Index);
	
	for (int ll=1, rr=m; x=(ll+rr)/2, ll<rr; )
	if (g(1,1,x,n,R)>=Index) rr=x; else ll=x+1;
	Index -= g(1,1,x-1,n,R);
	//printf("x=%d, Index=%lld\n", x, Index);
	
	for (int ll=1, rr=n; y=(ll+rr)/2, ll<rr; )
	if (g(x,1,x,y,R)>=Index) rr=y; else ll=y+1;
	printf("%d %d\n", x, y);
	if ((++Line)%1000==0) cerr << Line << endl;
}

main(){
	int p, q;
	while (scanf("%d%d%d", &m, &n, &p) > 0){
		if (!m && !n && !p) return 0;
		House.clear();
		f1(i,p) {
			int x, y; scanf("%d%d", &x, &y);
			House.push_back(ii(x, y));
		}
		scanf("%d", &q);
		f1(i,q) {
			long x; cin >> x;
			solve(x);
		}
		printf("-\n"); ++Line;
	}
}
