#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int MAX_N = 128;

int N[] = {4, 7, 10, 30, 50, 70, 90, 100, 110, 125};
int T[] = {6, 15, 25, 300, 400, 2500, 1500, 3000, 2999};
int A[MAX_N][MAX_N];

inline int random(int r) { return (rand() % r) + 1; }

void generate(int t) {
	memset(A, 0, sizeof(A));
	int v[MAX_N];
	for (int i = 1; i <= N[t]; ++i)
		v[i] = i;
	for (int i = N[t]; i; --i)
		swap(v[i], v[random(i)]);

	for (int i = 1; i <= N[t]; ++i)
		A[i][v[i]] = 1;

	for (int nr1 = 0; nr1 <= T[t]; ++nr1)
		A[random(N[t])][random(N[t])] = 1;
}

int main() {
	srand((int)time(0));
	for (int t = 0; t < sizeof(N)/sizeof(N[0]); ++t) {
		generate(t);

		ostringstream file;
		file << t + 1 << "-revolutie.in";
		ofstream fout(file.str().c_str());

		fout << N[t] << "\n";
		for (int i = 1; i <= N[t]; ++i) {
			for (int j = 1; j < N[t]; ++j)
				fout << A[i][j] << " ";
			fout << A[i][N[t]];
			fout << "\n";
		}
	}
}