// Marius Dumitran
// Solutie O(N^2)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;
#define maxn 5005
#define pi 3.14159265358

struct obiect{ int x1, x2, y1, y2, tip, index, raza; double arie ; };

time_t start;
obiect drep[ maxn ];
int last[ maxn ], nr[ maxn ] , SOL = -1, n, CINE = 0;

int cmpstruct( const void *a, const void *b)
{
	obiect c = *( obiect *)a;
	obiect d = *( obiect *)b;
	if( d.arie - c.arie > 0 ) return 1;
	if( d.arie - c.arie < 0 ) return -1;
	return 0;
}
inline int in( int x1, int y1, obiect a)
{
	if( a.tip == 0)
	{
		if( x1 >= a.x1 && x1 <= a.x2 && y1 >= a.y1 && y1 <= a.y2)
			return 1;
		else return 0;
	}
	return 0;
}
inline double dist( int x1, int y1, int x2, int y2)
{
	return sqrt( (double) ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) ) ;
}

inline int in( obiect a, obiect b)
{
	if( 0 == b.tip && a.tip == 0)
	{
		return ( in( a.x1, a.y1, b) + in( a.x1, a.y2, b) + in( a.x2, a.y1, b ) + in( a.x2 , a.y2, b) == 4 );
	}
	if( a.tip == 1 && b.tip == 1 )
	{
		if( dist( a.x1, a.y1, b.x1, b.y1) + a.raza <= (double)b.raza) return 1;
		return 0;
	}
	if( a.tip == 0 && b.tip == 1 )
	{
		if( dist( a.x1, a.y1, b.x1, b.y1) > b.raza ) return 0;
		if( dist( a.x1, a.y2, b.x1, b.y1) > b.raza ) return 0;
		if( dist( a.x2, a.y1, b.x1, b.y1) > b.raza ) return 0;
		if( dist( a.x2, a.y2, b.x1, b.y1) > b.raza ) return 0;
		return 1;
	}
	if( a.tip == 1 && b.tip == 0)
	{
		if( a.x1 - a.raza < b.x1 || a.x1 + a.raza > b.x2 || a.y1 - a.raza < b.y1 || a.y1 + a.raza > b.y2 )
			return 0;
		return 1;

	}
	return 0;
}



int main()
{
	start = clock();
	freopen("cuiburi.in", "r",stdin);
	freopen("cuiburi.out", "w",stdout);
	scanf("%d", &n);

	for( int i = 1; i <= n; ++i)
	{
		scanf("%d", &drep[ i ].tip);
		drep[ i ].index = i;

		if( drep[ i ].tip == 0)
		{
			scanf("%d %d %d %d", &drep[ i ].x1, &drep[ i ].y1, &drep[ i ].x2, &drep[ i ].y2);

			drep[ i ].arie = ( drep[ i].x2 - drep[ i ].x1 ) * ( drep[ i ].y2 - drep[ i ].y1 );
		}
		else{
			scanf("%d %d %d", &drep[ i ].x1, &drep[ i ].y1, &drep[ i ].raza);
			drep[ i ].arie = pi * drep[ i ].raza * drep[ i ].raza;
		}
	}

	//printf("%lf\n", ((double) clock() - start) / CLOCKS_PER_SEC);
	qsort( drep + 1, n, sizeof( drep[ 0 ]), cmpstruct);

	SOL = 0;
	CINE = 1;

	for( int i = 1; i <= n; ++i)
	{
		for( int j = 1; j < i; j++)
		{
			if( in (drep[ i], drep[ j ] ) && nr[ j ] + 1 > nr[ i ])
			{
				nr[ i ] = nr[ j ] + 1;
			//	last[ i ] = j;
			}
			if( nr[ i ] > SOL || (nr[ i ] == SOL && drep[i].index < CINE) )
				{ SOL = nr[ i ]; CINE = i; }
		}
	}
	printf("%d\n", SOL + 1);

	//printf("%lf\n", ((double) clock() - start) / CLOCKS_PER_SEC);

	/*vector < int > sol;
	while( CINE != 0)
	{
		sol.push_back( CINE );
		CINE = last[ CINE ];
	}
	for( int i = sol.size() - 1; i > 0; i--)
	{
		printf("%d ", drep[ sol[ i ]].index);
	}
	printf("%d\n", drep[ sol[ 0 ]].index);
	*/
	return 0;
}
