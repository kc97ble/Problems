#include<stdio.h>
#include<vector>
#define mkp make_pair
#define pb push_back
const int maxn = 100100;
using namespace std;
int LAST,FIRST,N,GR[maxn];
int VER[maxn],NEXT[maxn];
vector<pair<int,int> > VECT;

void dfs(int nod)
{
	VER[nod] = 1;
	if (VER[NEXT[nod]]) LAST = nod;
		else dfs(NEXT[nod]);
	return;	
}



int main()
{
	freopen("telefon.in","r",stdin);
	freopen("telefon.out","w",stdout);
	scanf("%d\n",&N);
	for(int i = 1;i <= N; ++i)
	{
		int x;
		scanf("%d",&x);
		NEXT[i] = x;	
		GR[x]++;
	}
	int ant = 0;
	int ver = 1;
	for(int i = 1;i <= N; ++i)
	{
		if (GR[i] == 0) 
		{
			dfs(i);
			if (FIRST == 0) FIRST = LAST;
			if (ant != 0)
			{
				NEXT[LAST] = ant;
				VECT.pb(mkp(LAST,ant));
			}	
			ant = i;
		}
	}
	for(int i = 1;i <= N; ++i)
		if (!VER[i])
		{
			NEXT[FIRST] = NEXT[i];
			VECT.pb(mkp(FIRST,NEXT[i]));
			FIRST = i;	
			int aux = NEXT[FIRST];
			while(aux != i)
			{
				VER[aux] = 1;
				aux = NEXT[aux];	
			}
			VER[aux] = 1;
		}
	NEXT[FIRST] = ant;
	VECT.pb(mkp(FIRST,ant));
	printf("%d\n",VECT.size());
	for(int i = 0;i < VECT.size(); ++i)
		printf("%d %d\n",VECT[i].first,VECT[i].second);
	return 0;
}




