#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> x1,x2;


class BinaryCards{
  public:
  long long largestNumber(long long A, long long B){
	  	  x1.clear(); x2.clear();
           while(A>0){ x1.push_back(A%2); A/=2;}
           while(B>0){ x2.push_back(B%2); B/=2;}
           int n = x1.size(), m = x2.size();
           if(n<m) return ((1LL<<(m))-1);
           long long kq = 0;
           int i;
           for(i = m-1;i>=0;i--){
                 if(x1[i]==x2[i]){
                       kq = kq*2+x2[i];
                 }
                 else break;
           }
           kq = (kq<<(i+1))+((1LL)<<(i+1))-1;
           return kq;
  }
}X;

long long a, b;
int main(){
//	freopen("in.txt", "r", stdin);
	while(cin >> a >> b){
		if(a == 0 && b == 0) break;
		cout << X.largestNumber(a, b) << endl;
	}
}
