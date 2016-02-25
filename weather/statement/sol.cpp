#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int dx[9] = {-1, 0, +1, 0, -2, 0, +2, 0, 0};
const int dy[9] = {0, -1, 0, +1, 0, -2, 0, +2, 0};

int n;
int festival[366][20];
int f[366][16][7][7][7][7];

int ok(int day, int u, int v) {
	if (u < 0 || u > 2 || v < 0 || v > 2) return 0;
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1; j++) {
		int pos = (u + i) * 4 + (v + j);
		if (festival[day][pos]) return 0;
	}
	return 1;
}

int process() {
	memset(f, 0, sizeof(f));
	f[1][5][1][1][1][1] = ok(1, 1, 1);
	if (n == 1) return f[1][5][1][1][1][1];

	for (int days = 1; days < n; days ++) {
		for (int pos = 0; pos < 16; pos++) {
			for (int d0 = 0; d0 < 7; d0++)
			for (int d3 = 0; d3 < 7; d3++)
			for (int d12 = 0; d12 < 7; d12++)
			for (int d15 = 0; d15 < 7; d15++) if (f[days][pos][d0][d3][d12][d15]) {
				int u = pos / 4;
				int v = pos % 4;
				for (int dir = 0; dir < 9; dir++) {
					int uu = u + dx[dir];
					int vv = v + dy[dir];
					if (ok(days + 1, uu, vv)) {
						int npos = uu * 4 + vv;
						int c0 = d0 + 1;
						int c3 = d3 + 1;
						int c12 = d12 + 1;
						int c15 = d15 + 1;
						if (npos == 0) c0 = 0;
						if (npos == 2) c3 = 0;
						if (npos == 8) c12 = 0;
						if (npos == 10) c15 = 0;
						if (c0 < 7 && c3 < 7 && c12 < 7 && c15 < 7) {
							f[days + 1][npos][c0][c3][c12][c15] = 1;
							if (days + 1 == n) return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	ofstream fi, fo;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test = 0;
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 16; j++) cin >> festival[i][j];
		}
		cout << process() << endl;
/*		test++;
		string name;
		if (test % 3 == 1) {
			name = "0";
			name[0] = '0' + test / 3 + 1;
			system(("md " + name).c_str());
			fi.open("weather.inp");
			fo.open("weather.out");
		}
		fi << n << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 16; j++) fi << festival[i][j] << " ";
			fi << endl;
		}
		fo << process() << endl;
		if (test % 3 == 0) {
			name = "0";
			name[0] = '0' + test / 3;
			fi << 0 << endl;
			fi.close();
			fo.close();
			cout << ("copy weather.inp " + name).c_str() << endl;
			cout << ("copy weather.out " + name).c_str() << endl;
			system(("copy weather.inp " + name).c_str());
			system(("copy weather.out " + name).c_str());
		}*/
	}
}
