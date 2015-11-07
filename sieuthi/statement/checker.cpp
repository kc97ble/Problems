#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 1024

struct Point
{
	double x, y;
};

int n, k;
Point points[MAX];
Point author[MAX];
Point contestant[MAX];

char errMsg[100]="Ok";

double fdist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int check(char* inpFile, char* solFile, char* outFile)
{
	FILE* in = fopen(inpFile, "rt");
	fscanf(in, "%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		fscanf(in, "%lf %lf", &points[i].x, &points[i].y);
	fclose(in);

	FILE* sol = fopen(solFile, "rt");
	for (int i = 0; i < k; i++)
	{
		if (fscanf(sol, "%lf %lf", &author[i].x, &author[i].y) != 2)
		{
			strcpy(errMsg, "Problem with author's solution!");
			return -1;
		}
	}
	fclose(sol);

	FILE* out = fopen(outFile, "rt");
	for (int i = 0; i < k; i++)
	{
		if (fscanf(out, "%lf %lf", &contestant[i].x, &contestant[i].y) != 2)
		{
			strcpy(errMsg,  "Problem with contestants's solution!");
			return -2;
		}
	}
	fclose(out);

	double authScore = 0.0;
	for (int i = 0; i < n; i++)
	{
		double minDist = fdist(points[i], author[0]);
		for (int c = 0; c < k; c++)
			minDist = std::min(minDist, fdist(points[i], author[c]));
		authScore += minDist;
	}

	double contScore = 0.0;
	for (int i = 0; i < n; i++)
	{
		double minDist = fdist(points[i], contestant[0]);
		for (int c = 0; c < k; c++)
			minDist = std::min(minDist, fdist(points[i], contestant[c]));
		contScore += minDist;
	}

	double fract = std::min(1.0, authScore / contScore);
	return (int)round(fract * fract * 100.0);
}

int main(int argc, char* argv[])
{
    
	int res = check(argv[1], argv[2], argv[3]);

    cout<<(res / 100.0)<<endl;
    cerr<<errMsg<<endl;

	return 0;
}
