#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

const int nn[25] = {2,2,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
const int kk[25] = {1,2,1,2,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3};
const int pp[25] = {0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};

int main() {
	for (int test = 1; test <= 25; test++) {
		int n = nn[test - 1];
		int k = kk[test - 1];
		int p = pp[test - 1];
		
		int x[10];
		int y[10];
		for (int i = 0; i < n; i++) {
			bool ok = true;
			while (true) {
				x[i] = rand() % 1000;
				y[i] = rand() % 1000;
				for (int j = 0; j < i; j++) if (x[i] == x[j] && y[i] == y[j]) ok = false;
				if (ok) break;
			}
		}
		vector<int> dist;
		for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) dist.push_back(abs(x[i]-x[j]) + abs(y[i]-y[j]));
		sort(dist.begin(), dist.end());
		int l = dist[n * n * p / 100] - 1;		
		
		string name = "??.in";
		name[0] = '0'+ test / 10;
		name[1] = '0'+ test % 10;
		ofstream f(name.c_str());
		f << n << " " << k << " " << l << endl;
		for (int i = 0; i < n; i++) f << x[i] << " " << y[i] << endl;	
		f.close();
	}
	return 0;
}

