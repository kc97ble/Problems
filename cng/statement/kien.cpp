#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 202
const int oo = 0x3c3c3c3c;
int n, k, Best=oo;
vector<int> a[N];
bool Choosen[N];

int evaluate() {
	int Count = 0;
	f1(u,n) if (Choosen[u]) {
		for (int i=0; int v=a[u][i]; i++)
		if (Choosen[v]) Count++;
	}
	Best = min(Best, Count/2);
	return Count/2;
}

void initial() {
	f1(i,n) Choosen[i] = i<=k;
	random_shuffle(Choosen+1, Choosen+n+1);
	evaluate();
}

void optimize(bool Better, int Times) {
	vector<int> L, R;
	f1(i,n) (Choosen[i] ? L : R).push_back(i);

	while (Times-->0) {
		int i=rand()%L.size(), x=L[i];
		int j=rand()%R.size(), y=R[j];
		Choosen[x]^=1; Choosen[y]^=1; swap(L[i], R[j]);
		if (evaluate()!=Best && Better)
		{ Choosen[x]^=1; Choosen[y]^=1; swap(L[i], R[j]); }
	}
}

main(){
	scanf("%d%d", &n, &k);
	int x, y;
	while (scanf("%d%d", &x, &y)>0) {
		a[x].push_back(y);
		a[y].push_back(x);
	}
	f1(i,n) a[i].push_back(0);
        if (k==0 || k==n) {
           initial();
           cout << evaluate() << endl;
        }
        else {
	  f1(i,20) {
		  initial();
                  f1(j,100)
                  optimize(true, 20);
	  }
	  cout << Best << "\n";
        }
}
