#include <stdio.h>
#include <string.h>

#define NMAX 100100

int i, j, k, p, N, M, nmoves;
char special[NMAX], cnt[NMAX];
int v[NMAX], marcat[NMAX], degin[NMAX], startChain[NMAX], endChain[NMAX];

void readInputData(void)
{
	freopen("telefon.in", "r", stdin);
	scanf("%d", &N);

	memset(degin, 0, sizeof(degin));

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &v[i]);
		degin[v[i]]++;
	}
}

void compute(void)
{
	int nmarcat = 0, nOne = 0;

	// mark the cycles
	memset(marcat, 0, sizeof(marcat));
	memset(special, 0, sizeof(special));

	for (i = 1; i <= N; i++)
		if (!marcat[i])
		{
			nmarcat++;

			k = i;
			while (!marcat[k])
			{
				marcat[k] = i;
				k = v[k];
			}

			if (marcat[k] != i)
				continue;

			j = v[k];
			while (!special[k])
			{
				special[k] = 1;
				k = j;
				j = v[k];
			}
		}

	nmoves = 0;
	
	// count the number of 1-degree vertices
	for (i = 1; i <= N; i++)
		if (degin[i] == 1)
			nOne++;
		
	if (nmarcat == 1 && nOne == N)
		return;

	// erase the multiple edges entering the same vertex 	
	memset(cnt, 0, sizeof(cnt));
	for (i = 1; i <= N; i++)
		if (degin[v[i]] > 1)
		{
			if (cnt[v[i]] == 0 && !special[i])
				cnt[v[i]]++;
			else
			{
				v[i] = 0;
				nmoves++;
			}
		}

	// break the cycles
	memset(marcat, 0, sizeof(marcat));
	for (i = 1; i <= N; i++)
		if (!marcat[i])
		{
			k = i;
			while (k > 0 && !marcat[k])
			{
				marcat[k] = 1;
				k = v[k];
			}

			if (k == i)
			{
				v[k] = 0;
				nmoves++;
			}
		}

	// now we only have chains => we need to connect them together
	memset(degin, 0, sizeof(degin));
	for (i = 1; i <= N; i++)
		if (v[i] > 0)
			degin[v[i]]++;

	M = 0;
	for (i = 1; i <= N; i++)
		if (degin[i] == 0)
		{
			M++;
			startChain[M] = i;

			k = i;
			while (v[k] > 0)
				k = v[k];

			endChain[M] = k;
		}
}

void writeOutputData(void)
{
	freopen("telefon.out", "w", stdout);
	printf("%d\n", nmoves);
	
	if (nmoves > 0)
	{
		for (i = 1; i <= M - 1; i++)
			printf("%d %d\n", endChain[i], startChain[i + 1]);
		printf("%d %d\n", endChain[M], startChain[1]);
	}
}

int main()
{
	readInputData();
	compute();
	writeOutputData();
	return 0;
}
