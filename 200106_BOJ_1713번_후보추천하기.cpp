#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct k {
	int idx, n, time;
	bool operator <(const k &o)const {
		if (n == o.n) return time > o.time;
		return n > o.n;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<k> lst;

	int N,K;
	cin >> N >> K;
	int time = 0;
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		
		bool get = false;
		
		for (auto iter = lst.begin(); iter != lst.end(); iter++) {
			
			if (iter->idx == num) {
				iter->n++;
				get = true;
			}
			

		}
		//cout << get <<"  "<< lst.size()<<"\n";
		if (get == false) {
			if (lst.size() == N) {
				sort(lst.begin(), lst.end());

				lst.pop_back();
				lst.push_back({ num,1,time });

			}
			else {
				lst.push_back({ num,1,time });
			}
		}

		time++;
		
	}


	
	
	vector<int> ans;

	for (auto k : lst)
		ans.push_back(k.idx);
	
	sort(ans.begin(), ans.end());

	for (auto n : ans)
		cout << n << " ";




	return 0;
}