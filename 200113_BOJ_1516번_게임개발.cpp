#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct goo {
	int idx, nowtime;
};

int N,time[501],a,in[501],ans[501];
vector<int> adlist[501];
queue<goo> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		
		cin >> time[i] >> a;

		while (a!=-1) {
			adlist[a].push_back(i);
			in[i]++;
			cin >> a;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) {
			q.push({ i,time[i] });
			ans[i] = time[i];
		}
	}

	while (!q.empty()) {
		int i = q.front().idx;
		int now = q.front().nowtime;
		//cout << i << " " << now << " \n";
		q.pop();
		for (auto wher : adlist[i]) {
			if(time[wher] + now>ans[wher])
				ans[wher] = time[wher] + now;
			in[wher]--;
			if (in[wher] == 0) {
				q.push({ wher,ans[wher] });
			}
		}

	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}