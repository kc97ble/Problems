//Code by Patcas Csaba
//Time complexity: O(N^2)
//Space complexity: O(L+N)
//Working time: 30 minutes

#include <stdio.h>
#include <vector>
#include <ctype.h>

using namespace std;

#define in_file "sirag.in"
#define out_file "sirag.out"
#define nBuf 8000005

#define FORN(i,n) for (int i=0;i<n;++i)
#define FOR(i,a,b) for (int i=a;i<=b;++i)

int n,l,ind,solution;
char buf[nBuf];
vector <int> a;
vector <bool> was;

void solve()
{
	was.clear();
	was.resize(n,false);
	solution=1;
	vector <int> cand(l);
	FORN(q,n+1-l-l)
		if (!was[q])
		{
			FOR(w,q,q+l-1) cand[w-q]=a[w];
			int start=q+l, now=1;
			while (start+l<=n)
			{
				++now;
				bool ok=true;
				FOR(w,start,start+l-1)
					if ( a[w] != '*' )
						if ( cand[w-start] == '*' ) cand[w-start]=a[w];
						else
							if (cand[w-start]!=a[w])
							{
								ok=false;
								break;
							}
				if (ok) 
				{
					if (a[start]!='*') was[start]=true;
					solution=max(solution,now);
				}
				else break;
				start+=l;
			}
	}
}

int main()
{
	FILE* fin=fopen(in_file, "r");
	FILE* fout=fopen(out_file, "w");
	int TestCases;
	fscanf(fin, "%d", &TestCases);
	
	for ( int i = 1; i <= TestCases; ++i ) {
  	  fscanf(fin,"%d %d \n",&n,&l);
  	  fscanf(fin, "%s \n", buf);
	  a.clear();
  	  a.resize(n);
  	  ind=0;
  	  FORN(q,n) a[q]=buf[q];
  	  solve();
  	  fprintf(fout,"%d\n",solution*l);
	  printf("%d\n",solution*l);
  }
  
  fclose(fin);
  fclose(fout);
	
  return 0;
}
