#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int n,arr[1000001],s,mx,idx;
priority_queue <int> pq[1000000];
vector <int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		
		if (s > 0) {
			bool ps = false;
			for (int k = 0; k < s; k++) {

				if (pq[k].top() < arr[i]) {
					pq[k].push(arr[i]);
					ps = true;
				}

				if (ps)break;
			}
			if (!ps) {
				pq[s].push(arr[i]);
				s++;
			}

		}
		else {
			pq[s].push(arr[i]);
			s++;
		}
	}
	for (int k = 0; k < s; k++) {

		if (pq[k].size() > mx) {
			mx = pq[k].size();
			idx = k;
		}

	}
	cout << pq[idx].size()<<"\n";

	while (!pq[idx].empty()) {

		ans.push_back(pq[idx].top());
		pq[idx].pop();
	}
	sort(ans.begin(), ans.end());


	for (int a : ans) {
		cout << a << " ";
	}
	


	return 0;
}