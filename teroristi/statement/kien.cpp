#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000006;
int n, m, b[27][27];
int Curr[27], Need[27]; 
int Visited[27], Visiting;
vector<int> Where[27][27];
char s[N];

int lend(int u, int Min) {
	if (Visited[u]==Visiting) return 0;
	else Visited[u] = Visiting;
	
	int Lent = 0;
	if (Curr[u]>Need[u]) {
		Lent = Curr[u]-Need[u];
		if (Lent >= Min) return Min;
	}
	for (int i=1; i<=26; i++){
		if (Lent>=Min || b[u][i]==0) continue;
		if (int x = lend(i, min(Min-Lent, b[u][i]))) {
			Curr[u] += x; Curr[i] -= x;
			b[u][i] -= x; b[i][u] += x;
			Lent += x;
		}
	}
	return Lent;
}

main(){
	freopen("teroristi.in", "r", stdin);
	freopen("teroristi.out", "w", stdout);
	
	scanf("%d%d%s", &n, &m, s+1);
	for (int i=1; i<=n; i++)
		Need[s[i]&31]++;
	for (int i=1; i<=m; i++) {
		char x, y; scanf(" %c %c", &x, &y); 
		x&=31, y&=31; 
		Curr[x]++; b[y][x]++;
		Where[x][y].push_back(i);
		Where[y][x].push_back(i);
	}
	for (int i=1; i<=26; i++) {
		while (Curr[i]<Need[i]) { 
			Visiting++;
			lend(i, Need[i]-Curr[i]);
		}
	}
	for (int i=1; i<=n; i++) {
		char c = s[i]&31;
		for (int j=1; j<=26; j++)
		if (b[j][c]) {
			b[j][c]--;
			printf("%d ", Where[j][c].back());
			Where[j][c].pop_back();
			Where[c][j].pop_back();
			break;
		} 
	}
}
