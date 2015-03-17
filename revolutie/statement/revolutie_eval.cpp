#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX_N = 128;

int n;
int a[MAX_N][MAX_N];

void terminate(int score, char* msg) {
	printf("%d %s\n", score, msg);
	exit(score==10 ? 0 : 1);
}

void lines(int x, int y) {
	for (int i = 1; i <= n; ++i)
		swap(a[x][i], a[y][i]);
}

void columns(int x, int y) {
	for (int i = 1; i <= n; ++i)
		swap(a[i][x], a[i][y]);
}

int main(int argc, char ** argv) {
	if (argc!=3) return -1;
	const char * FILEIN = argv[1];
	const char * FILEOUT = argv[2];
	
	freopen(FILEIN, "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);

	if (!freopen(FILEOUT, "r", stdin))
		terminate(0, "Fisier de iesire lipsa!");

	int op;
	if (scanf("%d", &op) != 1)
		terminate(0, "Raspuns gresit!");

	for (; op; --op) {
		char ch; int i1, i2;
		if (scanf(" %c %d %d", &ch, &i1, &i2) != 3) terminate(0, "Raspuns gresit!");
		if (ch != 'L' && ch != 'C') terminate(0, "Raspuns gresit!");
		if (i1 < 1 || i1 > n) terminate(0, "Raspuns gresit!");
		if (i2 < 1 || i2 > n) terminate(0, "Raspuns gresit!");
		if (ch == 'L') lines(i1, i2);
		if (ch == 'C') columns(i1, i2);
	}

	for (int i = 1; i <= n; ++i)
		if (a[i][i] != 1)
			terminate(0, "Raspuns gresit!");
	terminate(10, "OK!");
}
