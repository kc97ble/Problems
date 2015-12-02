#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef pair<long, long> llll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define X first
#define Y second

#define all(a) a.begin(), a.end()
const int oo=0x3c3c3c3c;

llll operator - (llll a, llll b)
	{ return llll(a.X-b.X, a.Y-b.Y); }
long operator * (llll a, llll b)
	{ return a.X*b.Y-a.Y*b.X; }
bool by_y(llll p, llll q)
	{ return p.Y < q.Y; }
double x_of(llll a, llll b, int y)
	{ return double(y-a.Y)/(b.Y-a.Y) * (b.X-a.X) + a.X; }
int intersect(ii a, ii b)
	{ return max(0, min(b.Y, a.Y) - max(a.X, b.X) + 1); }

struct points_t{
	vector<llll> List, Left, Right;
	void insert(int x, int y)
		{ List.push_back(llll(x, y)); }
	void execute() {
		llll Last=List.back();
		for (int i=0; i<List.size(); i++) {
			if (List[i].Y < Last.Y) {
				Right.push_back(List[i]);
				Right.push_back(Last);
			}
			if (List[i].Y > Last.Y) {
				Left.push_back(List[i]);
				Left.push_back(Last);
			}
			Last=List[i];
		}
		if ((List[1]-List[0]) * (List[2]-List[0]) > 0)
		swap(Left, Right);
		#define unique(a) a.erase(unique(all(a)), a.end())
		sort(all(Left), by_y); unique(Left);
		sort(all(Right), by_y); unique(Right);
	}

	#define index_of(x, T) (lower_bound(all(T), llll(-oo, x), by_y)-T.begin())
	ii get_limit(int y) {
		int L, R, i;

		i = index_of(y, Left);
		if (i==0)
			L = Left[i].X;
		else if (Left[i].Y==Left[i-1].Y)
			L = min(Left[i].X, Left[i-1].X);
		else {
			L = ceil(x_of(Left[i], Left[i-1], y));
			//printf("L=%d, %lld:%lld, %lld:%lld, %d\n",
			//L, Left[i].X, Left[i].Y, Left[i-1].X, Left[i-1].Y, y);
		}

		i = index_of(y, Right);
		if (i==0)
			R = Right[i].X;
		else if (Right[i].Y==Right[i-1].Y)
			R = max(Right[i].X, Right[i-1].X);
		else
			R = floor(x_of(Right[i], Right[i-1], y));

		return ii(L, R);
	}
} Points;

struct events_t {
	vector<iii> List;

	void insert(int y, int x1, int x2) {
		if (y<Points.Left[0].Y || y>Points.Left.back().Y) return ;
		List.push_back(iii(y, ii(x1, x2)));
	}

	long solve(int L, int R) {
		long Sum=0;
		int y = List[L].X;
		/*printf("\nsolve(y=%d)\n", y);
		for (int i=L; i<=R; i++)
		printf("%d..%d\n", List[i].Y.X, List[i].Y.Y);*/
		ii Limit=Points.get_limit(y);
		//printf("Limit=%d-%d\n", Limit.X, Limit.Y);

		int Start=L, Max=List[L].Y.Y;
		for (int i=L; i<=R; i++) {
			Max = max(Max, List[i].Y.Y);
			if (i==R || List[i+1].Y.X > Max) {
				ii Curr(List[Start].Y.X, Max);
				//printf("%d-%d = %d\n", Curr.X, Curr.Y, intersect(Limit, Curr));
				Sum += intersect(Limit, Curr);
				Start = i+1;
			}
		}
		return Sum;
	}

	long execute() {
		long Sum=0;
		sort(all(List));

		int Start=0;
		for (int i=0; i<List.size(); i++)
		if (i+1==List.size() || List[i].X!=List[i+1].X)
		{ Sum+=solve(Start, i); Start=i+1; }

		return Sum;
	}
} Events;

main() {
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Points.insert(x, y);
	}
	Points.execute();

	int m; scanf("%d", &m);
	for (int i=1; i<=m; i++) {
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		for (int dy=-r; dy<=r; dy++) {
			int dx = sqrt(1LL*r*r-1LL*dy*dy)+1e-9;
			//printf("event %d %d %d\n", y+dy, x-dx, x+dx);
			Events.insert(y+dy, x-dx, x+dx);
		}
	}
	cout << Events.execute() << endl;
}

