#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 100005
int n, Next[N], Prev[N];
bool Visited[N];
vector<int> Heads, Tails;

void visit(int u) {
	Visited[0]=Visited[u]=true;
	int Head=u, Tail=u;
	while (!Visited[Prev[Head]]) 
	{ Head=Prev[Head]; Visited[Head]=true; }
	while (!Visited[Next[Tail]]) 
	{ Tail=Next[Tail]; Visited[Tail]=true; }
	//printf("u=%d, Head=%d, Tail=%d\n", u, Head, Tail);
	Heads.push_back(Head);
	Tails.push_back(Tail);
}

main(){
	scanf("%d", &n);
	f1(i,n) {
		scanf("%d", &Next[i]);
		Prev[Next[i]]=i;
	}
	f1(i,n) if (!Visited[i]) visit(i);
	if (Heads.size()==1 && Next[Tails[0]]==Heads[0]) {
		cout << 0 << endl;
	} else {
		cout << Heads.size() << endl;
		f0(i,Tails.size()-1) 
		printf("%d %d\n", Tails[i], Heads[i+1]);
		printf("%d %d\n", Tails.back(), Heads[0]);
	}
}
