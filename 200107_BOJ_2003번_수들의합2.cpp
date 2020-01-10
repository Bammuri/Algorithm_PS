#include <iostream>
using namespace std;
int N, M,arr[10000];
int answer;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];

			if (sum == M)answer++;
			else if (sum > M)break;
		}
	}

	cout << answer;

	return 0;
}