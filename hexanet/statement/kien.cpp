#include <bits/stdc++.h>
using namespace std;

int rx[]={-1,-1,0,0,1,1};
int ry[]={0,1,-1,1,-1,0};

typedef pair<int, int> ii;
const int NN = 123, oo = 0x3c3c3c3c;
int nn, A[NN*2][NN*2], Peak;

const int N = 3003;
int a[N][6];
int n, d[64][N], Cost[N];

#define A(x, y) A[(x)+NN][(y)+NN]

int sign(int x)
	{ if (x==0) return 0; return x>0 ? +1 : -1; }
bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }

void fill(int x, int y, int u, int v) {
	int rx=sign(u-x), ry=sign(v-y);
	for (int i=x, j=y; i!=u || j!=v; ) 
	{ i+=rx, j+=ry; A(i, j)=++Peak; }
}

void dijkstra(int K) {
	//printf("dijkstra(%d)\n", K);
	#define d(u) d[K][u]
	priority_queue<ii> qu;
	for (int i=1; i<=n; i++)
	if (d(i)!=oo) qu.push(ii(-d(i), i));
	
	while (qu.size()) {
		ii w=qu.top(); qu.pop();
		int du=-w.first, u=w.second;
		if (d(u)!=du) continue;
		//printf("d[%d][%d] = %d\n", K, u, d(u));
		
		for (int k=0; k<6; k++)
		if (int v=a[u][k]) {
			if (minimize(d(v), d(u)+Cost[u]))
			qu.push(ii(-d(v), v));
		}
	}
}

main() {
	freopen("hexanet.inp", "r", stdin);
	freopen("hexanet.out", "w", stdout);
	
	scanf("%d", &nn);
	A(0, 0) = Peak = 1;
	for (int i=1; i<=nn; i++) {
		fill(-i, i, 0, i);
		fill(0, i, i, 0);
		fill(i, 0, i, -i);
		fill(i, -i, 0, -i);
		fill(0, -i, -i, 0);
		fill(-i, 0, -i, i);
	}

	/*for (int i=-nn; i<=nn; i++) {
		for (int j=-nn; j<=nn; j++)
		printf("%d ", A(i, j));
		printf("\n");
	}*/
	
	for (int i=-nn; i<=nn; i++)
	for (int j=-nn; j<=nn; j++)
	if (A(i, j)!=0) {
		for (int k=0; k<6; k++)
		a[A(i, j)][k]=A(i+rx[k], j+ry[k]);
	}
	
	n=1+3*nn*(nn+1);
	for (int i=1; i<=n; i++)
	scanf("%d", &Cost[i]);
	
	memset(d, 0x3c, sizeof d);
	int zx[]={-nn, 0, nn, nn, 0, -nn};
	int zy[]={nn, nn, 0, -nn, -nn, 0};
	for (int k=0; k<6; k++) {
		int u = A(zx[k], zy[k]);
		//printf("z[%d] = %d\n", k, u);
		d[1<<k][u]=0;
	}
	
	for (int k=0; k<64; k++) {
		for (int kk=0; kk<64; kk++) 
		if ((kk|k)==k) {
			for (int u=1; u<=n; u++)
			d[k][u] = min(d[k][u], d[kk][u]+d[k^kk][u]);
		}
		dijkstra(k);
	}
	cout << Cost[1] + d[63][1] << endl;
}

