//100p Nicoli Marius - CN "Fratii Buzesti" - Craiova
#include <stdio.h>
#include <string.h>

#define INF 65002

#define DIM 65002
#define DIM1 126

int DI[4] = {-1,1,0,0};
int DJ[4] = {0,0,1,-1};

char *V;
char *L;
char *C;

char *LL;
char *CC;

int *S;
int *W;

unsigned int P[DIM1][DIM1];

unsigned int i, j, N, M, x, max, K, Max, ic, jc, iv, jv, d, min, jMin, Vmax;

int main(){
	V = new char[DIM];
	memset(V,0,DIM);
	
	L = new char[DIM];
	memset(L,0,DIM);
	
	C = new char[DIM];
	memset(C,0,DIM);
	
	LL = new char[DIM1*DIM1];
	memset(LL,0,DIM1*DIM1);
	
	CC = new char[DIM1*DIM1];
	memset(CC,0,DIM1*DIM1);
	
	
	

	FILE *f = fopen("bila.in","r");
	fscanf(f,"%d %d",&N, &M);
	for (i = 1; i<=N; i++)
	for (j=1;j<=M;j++){
		fscanf(f,"%d",&x);
		V[x] = 1;
		L[x] = i;
		C[x] = j;
		if (x>max)
			max = x;
	}


	S = new int[DIM1*DIM1];
	W = new int[DIM1*DIM1];


	K = 0;
	for (i=0;i<=max;i++)
		if (V[i] == 1) {
			S[++K] = i;
			P[L[i]][C[i]] = K;
			LL[K] = L[i];
			CC[K] = C[i];
		}

	W[1] = 1;
	for (i=2;i<=K;i++){
		ic = LL[i];
		jc = CC[i];
		
		min = INF;
		max = 0;
		for (d = 0; d<=3; d++) {
			iv = ic + DI[d];
			jv = jc + DJ[d];
		
			if (iv>=1 && iv<=N && jv>=1 && jv<=M && (j = P[iv][jv])<i) {
				if (S[j]<min) {
					min = S[j];
					jMin = j;
				}
			}
		}
		
		if (min == INF)
			W[i] = 1;
		else
			W[i] = W[jMin]+1;
		
		if (W[i]>Max) {
			Max = W[i];
			Vmax = S[i];
		}
	}
	FILE * g = fopen("bila.out", "w");
	fprintf(g, "%d %d\n",Max,Vmax);
	fclose(g);
	fclose(f);
	return 0;
}
