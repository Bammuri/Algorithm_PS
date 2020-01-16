#include <iostream>
#include <string>
using namespace std;

string a, b;
int D[4002][4002];
int mxCnt = 0;

int main() {
	cin >> a >> b;

	for (int i = 1;i <= a.size() ; i++) {
		for (int j = 1; j <= b.size(); j++) {
			//cout << a[i] << " " << b[j] << "\n";
			if (a[i-1] == b[j-1]) {
				D[i][j] = D[i - 1][ j - 1]+1;
				//cout<<
				if (mxCnt < D[i][j])
					mxCnt = D[i][j];
			}
		
		}
	}
	

	cout << mxCnt;

	return 0;
}