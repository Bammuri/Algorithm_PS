#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct cmp {
	bool operator()(vector <int> t, vector <int> u) {
		return t[2] > u[2];
	}
};


priority_queue<vector<int>, vector<vector<int>>,cmp > pq;
vector<int> answer;
bool print = false;



vector<int> solution(vector<vector<int>> data) {
	int time = 0, idx = 1, tartime = 0, endtime= data[0][1];

	for (int i = 0; i < data.size(); i++) {
		endtime +=data[i][2];
	}
	do {
		if (idx > data.size())idx = 1;
		cout << time << " " << idx <<" "<<tartime<<"\n";

		if (data[idx-1][1] == time) {
		
			if (pq.empty() && !print) {
				print = true;
				tartime = time + data[idx-1][2];
				answer.push_back(idx++);
				cout << "1" << "\n";
			} else {
				pq.push(data[idx-1]);
				idx++;
				cout << "2" << "\n";
			}

			if (tartime == time) print = false;

			if (!pq.empty() && !print) {
				print = true;
				vector<int> tmp = pq.top();
				pq.pop();
				tartime = time + tmp[2];
				answer.push_back(tmp[0]);
				cout << "3" <<" "<< tmp[0] << "\n";
			}
		}
		if (tartime == time) print = false;

		if (!pq.empty() && !print) {
			print = true;
			vector<int> tmp = pq.top();
			pq.pop();
			tartime = time + tmp[2];
			answer.push_back(tmp[0]);
			cout << "4" << " " << tmp[0] << "\n";
		}

		time++;
	}while (endtime != time);

	return answer;
}

int main() {
	vector<vector<int>> input = { {1, 0, 5}, {2, 2, 2},{3, 3, 1},{4, 4, 1},{5, 10, 2 } };
	vector<vector<int>> input1 = { {1, 0, 3}, { 2, 1, 3 }, { 3, 3, 2 }, { 4, 9, 1 }, { 5, 10, 2 } };
	vector<vector<int>> input2 = {{1, 2, 10}, { 2, 5, 8 }, { 3, 6, 9 }, { 4, 20, 6 }, { 5, 25, 5 }};
	solution(input);


	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return  0;
}