#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool solution(vector <int> &List){
	map <int, int> m;
	map <int, int> visit;
	queue <pair<int,int>> q;
	
	int jump = 1;

	for (auto &num : List)
		m[num]++;

	q.push({1,jump});
	visit[1]++;
	while (!q.empty()){
		cout << q.front().first << '\n';
		for (int i = 0; i < q.size(); i++){
			int cur_lo = q.front().first;
			int jump = q.front().second;
			q.pop();

			int next_lo = cur_lo + jump - 1;
			if (m[next_lo] && !visit[next_lo]) {
				visit[next_lo] = 1;
				q.push({ next_lo, jump - 1 });
			}

			next_lo = cur_lo + jump;
			if (m[next_lo] && !visit[next_lo]) {
				visit[next_lo] = 1;
				q.push({ next_lo, jump });
			}

			next_lo = cur_lo + jump + 1;
			if (m[next_lo] && !visit[next_lo]) {
				visit[next_lo] = 1;
				q.push({ next_lo, jump + 1 });
			}
		}
	}
	if (visit[List[List.size() - 1]])
		return true;
	
	return false;
}



int main(){
	vector <int> v = { 0, 1, 3, 5, 6, 8, 12, 17 };
	cout<<solution(v);
	

}