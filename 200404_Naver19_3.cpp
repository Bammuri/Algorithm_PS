#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


struct st {
	int idx, time, page;
	bool operator <(const st& s) const {
		if (page == s.page)
			return time > s.time;
		return page > s.page;
	}
};

priority_queue<st> pq;

void solution(vector<vector<int>> &data, vector<int> &answer) {
	int time = 0, idx = 0, tartime = 0;
	bool print = false;
	      
	while ( !(idx == data.size() && pq.empty())){
			
		if (tartime == time)
			print = false;

				
		if (idx <data.size() && data[idx][1] == time) {
			pq.push({data[idx][0],data[idx][1],data[idx][2]});
			idx++;
		}

		if (!print && !pq.empty())
		{
			st can = pq.top();
			pq.pop();
			print = true;
			tartime = time + can.page;
			answer.push_back(can.idx);
			//cout<<"idx:" << can.idx << " ";
		}
		//cout << time << " " << tartime << " " << idx+1 << "\n";
		time++;
			  };

}

int main() {
	vector<vector<int>> input = { {1, 0, 5},{2, 2, 2},{3, 3, 1},{4, 4, 1},{5, 10, 2 } };
	vector <int >answer;
	solution(input, answer);

	for (auto n : answer) {
		cout << n << " ";
	}
	cout << "\n";
	vector<vector<int>> input2 = { {1, 0, 3},{2, 1, 3},{3, 3, 2},{4, 9, 1},{5, 10, 2}};
	vector <int >answer2;
	solution(input2, answer2);

	for (auto n : answer2) {
		cout << n << " ";
	}
	cout << "\n";
	vector<vector<int>> input3 = { {1, 2, 10},{2, 5, 8},{3, 6, 9},{4, 20, 6},{5, 25, 5} };
	vector <int >answer3;
	solution(input3, answer3);

	for (auto n : answer3) {
		cout << n << " ";
	}
	cout << "\n";
	return 0;
}