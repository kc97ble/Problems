#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct JOB
{
	long long dead;
	long long prof;
	bool operator <(const JOB &o) const
	{
		return dead < o.dead;
	}
};

long long N;
JOB job[100001];

int main(void)
{
	FILE *inFile = fopen("job.in", "rt");
	fscanf(inFile, "%lld", &N);
	for(long long i = 0 ; i < N ; i++)
		fscanf(inFile, "%lld%lld", &job[i].dead, &job[i].prof);
	fclose(inFile);
	job[N].dead = 0;
	job[N].prof = 0;
	N++;
	
	sort(job, job + N);
	
	priority_queue<long long> pq;
	long long curTime = 2000000000LL;
	long long profit = 0;
	for(long long i = N - 1 ; i >= 0 ; i--)
	{
		while(curTime > job[i].dead && pq.size())
		{
			curTime--;
			profit += pq.top();
			pq.pop();
		}
		
		curTime = job[i].dead;
		pq.push(job[i].prof);
	}
	
	FILE *outFile = fopen("job.out", "wt");
	fprintf(outFile, "%lld\n", profit);
	fclose(outFile);
	
	return 0;
}
