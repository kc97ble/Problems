#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define each(i,a) (__typeof(a.begin()) i=a.begin(); i!=a.end(); i++)

#define N 203
int n, A[N], B[N], C[N], Name[3][N];
int Visiting=0, Visited[N], Assigned[N], Peak=0;
vector<int> Left, a[N];

bool visit(int u){
	if (Visited[u]==Visiting) return false; Visited[u]=Visiting;
	for (int i=0; int v=a[u][i]; i++)
	if (!Assigned[v] || visit(Assigned[v])) 
	{ Assigned[u]=v; Assigned[v]=u; return true; }
	return false;
}

main(){
	scanf("%d", &n);
	f1(i,n) scanf("%d", &A[i]);
	f1(i,n) scanf("%d", &B[i]);
	f1(i,n) scanf("%d", &C[i]);
	f1(i,n) {
		Name[0][i]=++Peak; // Right
		Left.push_back(Name[1][i]=++Peak);
		Left.push_back(Name[2][i]=++Peak);
		//printf("%d [%d, %d, %d]\n", i, Name[0][i], Name[1][i], Name[2][i]);
	}
	
	f1(i,n) f1(j,n) 
	if (A[i]>=A[j] && B[i]>=B[j] && C[i]>=C[j])
	if (i<j || A[i]>A[j] || B[i]>B[j] || C[i]>C[j]){
		a[Name[1][i]].push_back(Name[0][j]);
		a[Name[2][i]].push_back(Name[0][j]);
	}
	f1(i,Peak) a[i].push_back(0);
	
	int Sum = 0;
	for each(it, Left) {
		Visiting++;
		Sum += visit(*it);
	}
	cout << n-Sum << endl;	
}
