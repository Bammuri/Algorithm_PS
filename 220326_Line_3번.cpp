
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
vector<int> teamIdx;
vector<int> teamemnum;

vector<int> solution(int num_teams, vector<string> remote_tasks, vector<string> office_tasks, vector<string> employees) {
	vector<int> answer;
	int team;
	string task;
	vector<int> teamIdx( num_teams+1);
	vector<int> teamemnum(num_teams+1);

	int i = 0;
	for (auto str : employees) {
		i++;
		stringstream ss(str);
		ss >> team;
		if (teamemnum[team] == 0)
			teamemnum[team] = i;
		bool continuF = 0;
		while (ss >> task) {
			for (auto offi : office_tasks) {
				if (task == offi) {
					
					continuF = 1;
					break;
				}
			
			}
			if (continuF) break;
		}
		if (!continuF) {
			
			answer.push_back(i);
		}
		if (continuF) {
			teamIdx[team] = 1;
		}
	
	}
	
	for (int i = 1; i <= num_teams; i++) {
		if (!teamIdx[i]) {
			for(int k=0;k<answer.size();k++)
				if(answer[k]== teamemnum[i])
					answer.erase(answer.begin()+ k);

		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}


int main() {
	/*
	vector<string> remote_tasks = { "development","marketing","hometask" };
	vector<string> office_tasks = {"recruitment", "education", "officetask"};
	vector<string> employees = {"1 development hometask","1 recruitment marketing","2 hometask","2 development marketing hometask","3 marketing","3 officetask","3 development"};
	int num_teams = 3;
	*/
	vector<string> remote_tasks = { "design" };
	vector<string> office_tasks = { "building","supervise" };
	vector<string> employees = { "2 design","1 supervise building design","1 design","2 design" };
	int num_teams = 2;
	
	vector<int> ans;
	ans= solution(num_teams, remote_tasks, office_tasks, employees);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}