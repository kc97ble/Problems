#include <cstdio>
#include <cstring>

#define REP(i, n) for( int i = 0, _n = (n); i < _n; ++i )

//---------------------------------------------------------------------------------------------------------------------------------------------------------
char a[100][100];
int n, m;
//---------------------------------------------------------------------------------------------------------------------------------------------------------
void input() {
	scanf("%d\n", &n);
	REP(i, n) gets(a[i]);
	m = strlen(a[0]);
}

void countRow( int & r ) {
	int len;
	REP(i,n) {
		int j = 0;
		while( j < m ) {
			len = 0;
			while ( j < m && a[i][j] == '#' ) ++j;
			while ( j < m && a[i][j] == '.' ) {
				++j; ++len;
			}
			if(len>1) ++r;
		}
	}
}

void countCol( int & c ) {
	int len;
	REP(j, m) {
		int i = 0;
		while( i < n ) {
			len = 0;
			while ( i < n && a[i][j] == '#' ) ++i;
			while ( i < n && a[i][j] == '.' ){
				++i; ++len;
			}
			if(len>1) ++c;
		}
	}
}

void solve() {
	int sharp = 0;
	REP(i, n) if (strchr(a[i], '#') != NULL) {
		sharp = 1; break;
	}
	if (sharp) {
		int r = 0, c = 0, len;
		countRow(r);
		countCol(c);
		printf( "%d\n", r > c ? r : c );
	} else {
		printf( "%d\n", m > n ? n : m );
	}
}

int main() {
//	freopen( "foxbomb.inp", "r", stdin );
//	freopen( "foxbomb.out", "w", stdout );
	input();
	solve();
	return 0;
}
