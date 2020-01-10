#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;

vector<int> A;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		
		cin >> num;
		A.push_back(num);
	}

	sort(A.begin(), A.end());
	cin >> M;
	int tmp;

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (binary_search(A.begin(), A.end(), tmp) )
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
			
		
	}


	return 0;
}