#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 10000*42*42;
int n, a[N][27], Peak=0;
bool IsLeaf[N], IsSuffix[27];
char Char[N], Root[N], Depth[N];
int Count[27];

int create(int r, char c, int d) {
	int u=++Peak;
	Char[u]=c;
	Root[u]=r;
	Depth[u]=d;
	return u;
}

bool insert(int u, char s[], int r) {
	for (int i=0; char c=s[i]; i++) {
		if (a[u][c]==0) a[u][c]=create(r, c, Depth[u]+1);
		u=a[u][c];
	}
	if (IsLeaf[u]) return false;
	return IsLeaf[u]=true;
}

main(){
	Peak=26;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		char s[41]; scanf("%s", s);
		for (int j=0; s[j]; j++) 
			s[j] &= 31;
		insert(0, s, 0);
		IsSuffix[s[strlen(s)-1]]=true;
		for (int j=0; s[j]; j++) 
			Count[s[j]] += insert(s[j], s+j, s[j]);
	}
	/*for (int i=1; i<=26; i++)
		if (int x = Count[i])
		printf("Count[%d] = %d\n", i, x);*/
	long Sum = 0;
	for (int u=27; u<=Peak; u++) if (Root[u]==0) {
		//printf("u=%d, Sum=%lld\n", u, Sum);
		if (IsSuffix[Char[u]] && Depth[u]!=1 || IsLeaf[u]) Sum++;
		for (int i=1; i<=26; i++)
		if (a[u][i]==0) Sum+=Count[i];
	}
	cout << Sum << endl;
}
