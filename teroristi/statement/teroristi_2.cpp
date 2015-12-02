// Marius Dragus - 50 puncte
#include<stdio.h>
#include<bitset>
#include<vector>
#define pb push_back

using namespace std;

const int maxn = 1000000;
int N,M;
bitset <maxn>  VER;
vector<int> VECT[maxn];
int ST[maxn],DR[maxn];
char S[maxn];

bool cupleaza(int nod)
{
	if (VER[nod] == 1) return false;
	VER[nod] = 1;
	for(int i = 0;i < VECT[nod].size(); ++i)
	{
		int vec = VECT[nod][i];
		int cupl = ST[vec];
		if (cupl == 0 || cupleaza(cupl))
		{
			DR[nod] = vec;
			ST[vec] = nod;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("teroristi.in","r",stdin);
	freopen("teroristi.out","w",stdout);
	scanf("%d %d\n",&N,&M);
	fgets(S + 1,1000000,stdin);
	for(int i = 1;i <= M; ++i)
	{
		char a,b;
		scanf("%c %c\n",&a,&b);
		for(int j = 1;j <= N; ++j)
			if (S[j] == b || S[j] == a)
			{
			//	printf("%d %d\n",j,i);
				VECT[j].pb(i);
			}
	}
	int move = 1;
	while(move)
	{
		move = 0;
		for(int i = 1;i <= N; ++i) VER[i] = 0;
		for(int i = 1;i <= N; ++i)
			if (!DR[i]) move |= cupleaza(i);

	}
	for(int i = 1;i <= N; ++i)
		printf("%d ",DR[i]);
	return 0;
}



