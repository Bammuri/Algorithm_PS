#include <iostream>
using namespace std;
int arr[1001];
int N, K;
int getans() {

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (!arr[j]) {
				arr[j] = 1;
				K--;
				//cout << j << " ";
			}
			if (K == 0) {
				return j;
			}
		}

	}


}

int main() {
	cin >> N >> K;

	cout<<getans();
	return 0;
}