#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<double, int> ii;
typedef vector<ii> :: iterator pii;
#define X first
#define Y second

#define N 202
const int oo = 0x3c3c3c3c;
int n, a[N];
double H[N][N];
int b[N][N], Row[N], Col[N]; //
int B[N][N], R[N], C[N]; //

void init() {
	#define reset(a) memset(a, 0, sizeof a);
	reset(b); reset(Row); reset(Col);
	reset(B); reset(R); reset(C);
}

void set1(int x, int y, int k) {
	R[x]-=!!B[x][y]; C[y]-=!!B[x][y];
	B[x][y] += k;
	R[x]+=!!B[x][y]; C[y]+=!!B[x][y];
}

void set(int x, int y, int k) {
	Row[x]+=k; Col[y]+=k; b[x][y]+=k;
	a[x]=(b[x][y] ? y : 0);
	for (int i=1; i<=n; i++) set1(x, i, k);
	for (int i=1; i<=n; i++) set1(i, y, k);
	for (int i=x, j=y; i<=n && j<=n; i++, j++) set1(i, j, k);
	for (int i=x, j=y; i<=n && j>=1; i++, j--) set1(i, j, k);
	for (int i=x, j=y; i>=1 && j<=n; i--, j++) set1(i, j, k);
	for (int i=x, j=y; i>=1 && j>=1; i--, j--) set1(i, j, k);
}

double h() {
	double P=1;// int A=0, B=0;
	for (int i=1; i<=n; i++) {
		if (!Row[i]) P = P * (n-R[i]) / n;
		//A+=(n-R[i]); B+=n;
	}
	for (int i=1; i<=n; i++)
		if (!Col[i]) P = P * (n-C[i]) / n;
	//P=P*A/B;
	return P;
}

int best_row() {
	double Min = 9e23;
	int Best = 0;

	for (int i=1; i<=n; i++) if (!Row[i]) {
		double Max = -1.0;
		for (int j=1; j<=n; j++)
			if (!B[i][j])
			Max = max(Max, H[i][j]);
		if (Max<Min) { Min=Max; Best=i; }
	}
	return Best;
}

bool btrk(int r, int k) {
	if (r==0) {
		for (int i=1; i<=n; i++)
		printf(i==n ? "%d\n" : "%d ", a[i]);
		return true;
	}
	for (int i=1; i<=n; i++) if (!Row[i])
	for (int j=1; j<=n; j++) if (!B[i][j]) {
		set(i, j, +1);
		H[i][j] = h();
		set(i, j, -1);
	}
	int i=best_row();
	vector<ii> List;
	for (int j=1; j<=n; j++) if (!B[i][j])
		List.push_back(ii(H[i][j], j));
	sort(List.rbegin(), List.rend());
	int k1=k;
	for (pii it=List.begin(); it!=List.end(); it++) {
		int j=it->Y;
		set(i, j, +1);
		if (btrk(r-1, k1)) return true;
		set(i, j, -1);
		if (k1==1) break; else k1--;
	}
	return false;
}

main(){
	while (scanf("%d", &n) > 0) {
		init();
		int Remain = 0;
		for (int i=1; i<=n; i++) {
			int x; scanf("%d", &x);
			if (x) set(i, x, +1);
			else Remain++;
		}
		if (!btrk(Remain, 5))
		cout << -1 << endl;
	}
}

