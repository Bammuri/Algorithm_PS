#include <algorithm>
#include <queue>
#include <map>

int solution(vector<int> &A) {

	priority_queue<int> pq;
	map<int, int> m;
	int Asize = A.size();
	int answer = 0;

	sort(A.begin(), A.end());

	for (auto a : A) {
		if (m[a] != 0 || a > Asize) continue;

		m[a]++;
		pq.push(a);
	}

	while (!pq.empty()) {

		int n = pq.top();
		pq.pop();

		int c = (int)(upper_bound(A.begin(), A.end(), n) - lower_bound(A.begin(), A.end(), n));
		if (n == c) {
			answer = n;
			break;
		}
	}

	return answer;
}