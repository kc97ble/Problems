/* Airinei Adrian, sursa brute */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define pb push_back
#define MAXN 100100

int N, M, X, dmin[MAXN];
vector<int> G[MAXN];
int ok[MAXN], viz[MAXN], aux[MAXN];

int bfs(int x)
{
	queue<int> Q;
	vector<int>::iterator it;
	aux[0] = 1, aux[1] = x;
	Q.push(x), viz[x] = 1, dmin[x] = 0;
	while(1)
	{
		int y = Q.front(); Q.pop();
		if(ok[y] && y != x) {
			for(int i = 1; i <= aux[0]; i++)
				viz[aux[i]] = 0;
			return dmin[y];
		}
		for(it = G[y].begin(); it != G[y].end(); it++)
			if(!viz[*it])
				viz[*it] = 1, dmin[*it] = dmin[y]+1, Q.push(*it), aux[++aux[0]] = *it;
	}
}

int main(void)
{
	freopen("reinvent.in", "rt", stdin);
	freopen("reinvent.out", "wt", stdout);
	int i, j, a, b;
	scanf ("%d %d %d\n", &N, &M, &X);
	for(i = 1; i <= M; i++)
	{
    char sir[256];
    fgets(sir, 256, stdin);
    int ind = 0;
    for(a = 0; sir[ind] >= '0' && sir[ind] <= '9'; ind++)
      a = a * 10 + (sir[ind]-'0');
    ind++;
		for(b = 0; sir[ind] >= '0' && sir[ind] <= '9'; ind++)
      b = b * 10 + (sir[ind]-'0');
    //scanf("%d %d", &a, &b);
		//scanf("%d %d", &a, &b);
		G[a].pb(b), G[b].pb(a);
	}
	for(i = 1; i <= X; i++)
		scanf("%d ", &a), ok[a] = 1;
	int res = (1<<30);
	for(i = 1; i <= N; i++)
		if(ok[i])
			res = min(res, bfs(i));
	printf("%d\n", res);
	return 0;
}







