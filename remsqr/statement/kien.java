import java.util.Scanner;

class disjoint_set {
	int P[];
	disjoint_set(int N)
		{ P = new int[N]; for (int i=0; i<N; i++) P[i]=i; }
	void join(int a, int b) 
		{ P[root(a)]=root(b); }
	int root(int u)
		{ if (u==P[u]) return u; return P[u]=root(P[u]); }
}

public class kien {
	static Scanner cin = new Scanner(System.in);
	
	public static void main(String args[]) 
		{ System.out.println(new kien().solve()); }
	
	int m = cin.nextInt();
	int n = cin.nextInt();
	char a[][] = new char[m+2][n+2];
	
	int f(int x, int y)
		{ return x*n-y; }
	
	int solve() {
		
		for (int i=1; i<=m; i++)
		a[i] = ("\0"+cin.next()+"\0").toCharArray();
		
		disjoint_set L = new disjoint_set(m*n);
		
		for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++) {
			if (i<m && a[i][j]=='#' && a[i+1][j]=='#')
			L.join(f(i, j), f(i+1, j));
			if (j<n && a[i][j]=='#' && a[i][j+1]=='#')
			L.join(f(i, j), f(i, j+1));
		}
		int Count = 0;
		for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
		if (a[i][j]=='#') 
		Count += (L.root(f(i, j))==f(i, j) ? 1 : 0);
		
		return Count;
	}
}
