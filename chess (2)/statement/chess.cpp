#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("chess.in");
    ofstream out("chess.out");

    int n;
    in >> n;
	int k = -1;
	int h;
	for (int i = 1; i <= n; i++) {
		in >> h;
		if (h < i) {
			k = i - 1;
			break;
		} 
	}

	if (k == -1)
		k = n;
		
    out << k << '\n';
    for (int i = 0; i < k; i++) {
		out << (i + 1) << ' ' << (i + 1) << '\n';
    }

    return 0;
}