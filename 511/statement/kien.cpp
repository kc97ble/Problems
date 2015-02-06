#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 1003
int n, a[N], Count[N];
bool FF[2][2][N], F[2][2][N];
#define C Player][CanAsk][u

bool g(int u, int Player, bool CanAsk);

bool f(int u, int Player, bool CanAsk){
	bool F = g(u,Player,CanAsk);
	//printf("f(%d, %d, %d) = %d\n", u, Player, int(CanAsk), F);
	return F;
}

bool g(int u, int Player, bool CanAsk){
	if (u==511) return true;
	if (FF[C]++) return F[C];
	f1(i,n) if ((a[i]|u)!=u) {
		if (f(a[i]|u, !Player, true)==false)
		return F[C]=true;
	}
	if (CanAsk && !f(u, !Player, false)) 
	return F[C]=(Count[u]&1)!=Player;
	return F[C]=false;
}

main(){
	scanf("%d", &n);
	f1(i,n) scanf("%d", &a[i]);
	f1(i,n) f0(k,512) if ((a[i]|k)==k) Count[k]++;
	cout << (f(0, 0, 1) ? "FoxCiel" : "Toastman") << endl;
}
