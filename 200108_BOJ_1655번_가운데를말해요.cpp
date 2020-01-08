#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N,num,ans=0;

priority_queue <int, vector<int>> lq;
priority_queue <int, vector<int>, greater<int>> hq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;


		if (lq.empty()&&hq.empty()) {
			lq.push(num);

		}
		else {


			if (lq.top() > num) {
				lq.push(num);
			}
			else {
				hq.push(num);
			}

			if (lq.size()<hq.size()) {
				lq.push(hq.top());
				hq.pop();
			}
			else if(lq.size()-1>hq.size()){
				hq.push(lq.top());
				lq.pop();
			}

		}
		cout << lq.top() << "\n";
	}


	return 0;
}