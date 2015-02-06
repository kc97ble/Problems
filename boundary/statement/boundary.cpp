#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define point pair<int,int>
#define PI acos(-1.0)
using namespace std;

point s;
int n,r;
vector< pair<double,double> > a,v;

double angle(point A,point B)
{
	double x = B.first - A.first;
	double y = B.second - A.second;
	double anl = atan2(y,x);
	if (anl <= 0) anl += 2 * PI;
	return anl;
};

point find_next(point A)
{
	int x = A.first,y = A.second;
	if (x == n)
	{
		if (y == n) x--; else y++;
	}
	else if (x == 0)
	{
		if (y == 0) x++; else y--;
	}
	else
	{
		if (y == 0) x++; else x--;
	};
	return make_pair(x,y);
};

int main()
{
//	freopen("boundary.in","r",stdin);
//	freopen("boundary.out","w",stdout);
	scanf("%d %d", &n, &r);
	scanf("%d %d", &s.first, &s.second);
	
	for (int i = 0; i < r; i++)
	{
		vector<double> p;  int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			point t;
			scanf("%d %d", &t.first, &t.second);
			double tmp = angle(s,t);			
			p.push_back(tmp);
		};
		sort(p.begin(),p.end());		
		for (int j = 0; j < num - 1; j++) if (p[j + 1] - p[j] < PI) v.push_back(make_pair(p[j],p[j + 1]));
		if (p[num - 1] - p[0] >= PI)
		{
			v.push_back(make_pair(p[num - 1],2 * PI));
			v.push_back(make_pair(0,p[0]));
		};
	};
	
	sort(v.begin(),v.end());	
	v.push_back(make_pair(100.0,100.0));
	double low = v[0].first,high = v[0].second;
	for (int i = 1; i < v.size(); i++)
	  if (v[i].first > high)
	  {
			a.push_back(make_pair(low,high));
			low = v[i].first;  high = v[i].second;
      }
      else high = max(high,v[i].second);
	  
	int ret = 0;
	point next = make_pair(n,s.second + 1),fin = next;  int last = 0,pt = a.size();
	
//	for (int i = 0; i < a.size(); i++) cout << a[i].first << ' ' << a[i].second << endl;
	while (1)
	{				
		double anl = angle(s,next);
		while (last < pt && a[last].second < anl) last++;
		if (last >= pt || a[last].first > anl) ret++; 
//		cout << "next angle: " << anl << ' ' << ret << endl;			
		next = find_next(next);
		if (next == fin) break;
	};	
	printf("%d\n", ret);          
};
