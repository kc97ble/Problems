// Marius Dragus
// Solutie O(N^2)

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define pb push_back

using namespace std;

const int maxn = 6000;
const double PI = 3.141592653589793;

inline bool between(int xmin,int xmax,int xmin1,int xmax1)
{
	return ((xmin <= xmin1) && (xmax1 <= xmax));
}

int TIP[maxn],NIV,XMIN[maxn],XMAX[maxn],YMIN[maxn],YMAX[maxn];
int NEXT[maxn],X[maxn],Y[maxn],R[maxn],D[maxn],N,ANS,IND[maxn];
double ARIE[maxn];

bool cmpf(int ind,int ind1)
{
	return ARIE[ind] < ARIE[ind1];
}

double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

}

int main()
{
	freopen("cuiburi.in","r",stdin);
	freopen("cuiburi.out","w",stdout);
	scanf("%d\n",&N);
	for(int i = 1;i <= N; ++i)
	{
		scanf("%d\n",&TIP[i]);
		if (!TIP[i])
		{
			scanf("%d %d %d %d\n",&XMIN[i],&YMIN[i],&XMAX[i],&YMAX[i]);
			D[i] = 1;
			ARIE[i] = (XMAX[i] - XMIN[i]) * (YMAX[i] - YMIN[i]);
		}
		else
		{
			scanf("%d %d %d\n",&X[i],&Y[i],&R[i]);
			XMIN[i] = X[i] - R[i];
			XMAX[i] = X[i] + R[i];
			YMIN[i] = Y[i] - R[i];
			YMAX[i] = Y[i] + R[i];
			D[i] = 1;
			ARIE[i] = (double)PI * R[i] * R[i];
		}
		IND[i] = i;
	}
	sort(IND + 1,IND + N + 1,cmpf);
	for(int i1 = 1;i1 <= N; ++i1)
	{
		int i = IND[i1];
		for(int j1 = 1;j1 < i1; ++j1)
		{
			int j = IND[j1];
			if (TIP[i] == 0)
			{
				if (between(YMIN[i],YMAX[i],YMIN[j],YMAX[j]) && between(XMIN[i],XMAX[i],XMIN[j],XMAX[j]))
				{
					D[i] = max(D[i],D[j] + 1);
					if (D[i] == D[j] + 1) NEXT[i] = j;
				}
			}
			else
			{
				if (TIP[j] == 1)
				{
					if (dist(X[i],Y[i],X[j],Y[j]) + R[j] <= R[i])
					{
						D[i] = max(D[i],D[j] + 1);
						if (D[i] == D[j] + 1) NEXT[i] = j;

					}
				}
				else
				{
					double nr1 = dist(X[i],Y[i],XMIN[j],YMIN[j]);
					double nr2 = dist(X[i],Y[i],XMIN[j],YMAX[j]);
					double nr3 = dist(X[i],Y[i],XMAX[j],YMIN[j]);
					double nr4 = dist(X[i],Y[i],XMAX[j],YMAX[j]);
					if (nr1 <= R[i] && nr2 <= R[i] && nr3 <= R[i] && nr4 <= R[i])
					{
						D[i] = max(D[i],D[j] + 1);
     						if (D[i] == D[j] + 1) NEXT[i] = j;
					}
				}
			}
		}
		if (D[i] > ANS) ANS = D[i];
	}
	printf("%d\n",ANS);
	return 0;
}


