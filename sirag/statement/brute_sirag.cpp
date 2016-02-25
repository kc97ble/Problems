#include <fstream>
#include <string.h>

using namespace std;

#define MAXN 100010
#define Sigma 26

int T, N, L, Sol;
char A[MAXN];
int match[MAXN];

int main()
{
	ifstream fin("sirag.in");
	ofstream fout("sirag.out");

	int i, j, k, found;

	fin >> T;

	for (; T; T--)
	{
		fin >> N >> L >> (A+1);
		Sol = 0;

		for (i = 1; i <= N; i++)
		{
			memset(match, -1, sizeof(match));

			for (j = i; j-L >= 0; j -= L)
			{
				found = 0;
				for (k = 0; k < L; k++) 
					if (A[j-k] != '*')
					{
						if (match[k] == -1) match[k] = A[j-k] - 'a';
						else if (match[k] != A[j-k] - 'a') 
							 {
								 found = 1;
								 break;
							 }
					}

				if (found) break;

				Sol = max(Sol, i-j+L);
			}
		}

		fout << Sol << endl;
	}

	return 0;
}
