#include <bits/stdc++.h>
using namespace std;

const int limit = 1000 + 5;
int n;
int a[limit][limit];
bool b[limit][limit];
int sum[limit][limit];
int rightLeftDiag[limit][limit];
int leftRightDiag[limit][limit];
vector< pair<int,int> > important;

void updateRectagle(int i, int j, int ii, int jj){
	sum[i][j]++;
	sum[i][jj+1]--;
	sum[ii+1][j]--;
	sum[ii+1][jj+1]++;
}

void updateRightLeftDiag(int i, int j, int ii, int jj){
	if (i > ii) return;
	rightLeftDiag[i][j]++;
	rightLeftDiag[ii+1][jj-1]--;
}

void updateLeftRightDiag(int i, int j, int ii, int jj){
	if (i > ii) return;
	leftRightDiag[i][j]++;
	leftRightDiag[ii+1][jj+1]--;
}

int main(){	
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= n; ++j){
		scanf("%d",&a[i][j]);
		if (a[i][j]) important.push_back( pair<int,int> (i, j) );
	}
	
	memset(b, true, sizeof b);
	if ( (int)important.size() <= n*2 ){
		sort(important.begin(), important.end());
		for(int i1 = 0; i1 < (int)important.size(); ++i1)
		for(int i2 = i1+1; i2 < (int)important.size(); ++i2){
			int i = important[i1].first, j = important[i1].second;
			int ii = important[i2].first, jj = important[i2].second;
			if ( (i+j)%2 != (ii+jj)%2 ) continue;
			int length = abs(i-ii) + abs(j-jj);
			if ( abs(i-ii) == abs(j-jj) ){
				if (i-j == ii-jj){
					updateRightLeftDiag(i,jj,ii,j);
					updateRectagle(1, jj, i, n);
					updateRectagle(ii, 1, n, j);
				} else if (i+j == ii+jj){
					updateLeftRightDiag(i,jj,ii,j);
					updateRectagle(1,1,i,jj);
					updateRectagle(ii,j,n,n);
				} 			
			} else if (abs(i-ii) > abs(j-jj)){
				int top = ii - length/2;
				int bot = i + length/2;
				if (j <= jj){
					updateRightLeftDiag(top,jj,bot,j);
					updateRectagle(top,jj, top,n);
					updateRectagle(bot,1, bot,j);				
				} else {
					updateLeftRightDiag(top,jj,bot,j);
					updateRectagle(top,1,top,jj);
					updateRectagle(bot,j,bot,n);	
				}
			} else {							
				int lo = max(jj,j) - length/2;
				int hi = min(j,jj) + length/2;
				if (j < jj){
					updateRightLeftDiag(i,hi,ii,lo);
					updateRectagle(1,hi,i,hi);
					updateRectagle(ii,lo,n,lo);
				} else {
					updateLeftRightDiag(i,lo,ii,hi);
					updateRectagle(1,lo,i,lo);
					updateRectagle(ii,hi,n,hi);
				}
			
			}
		}
		
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
			leftRightDiag[i][j] += leftRightDiag[i-1][j-1];
			rightLeftDiag[i][j] += rightLeftDiag[i-1][j+1];
			b[i][j] = sum[i][j] | leftRightDiag[i][j] | rightLeftDiag[i][j];
		}
	}
		
		
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < n; ++j) printf("%d ", (int)b[i][j]);
		printf("%d\n", (int)b[i][n]);	
	}
		
	

}