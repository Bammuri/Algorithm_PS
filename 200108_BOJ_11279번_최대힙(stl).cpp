#include <iostream>
#include <functional>
#include <queue>
using namespace std;
int N, num;

priority_queue <int, vector<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num != 0) {
			pq.push(num);
		}
		else {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				cout << "0" << "\n";
			}
		}


	}

	return 0;
}