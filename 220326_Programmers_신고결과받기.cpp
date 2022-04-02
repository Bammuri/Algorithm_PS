#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>
#include <iostream>


using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size(), 0);

	unordered_map<string, int> idxMap;
	for (int i = 0; i < id_list.size(); ++i) idxMap[id_list[i]] = i;

	unordered_map<string, set<string>> reportMap;
	stringstream ss;
	for (auto& rep : report) {
		ss.str(rep);
		string first, second; ss >> first >> second;//first가 second를 신고
		reportMap[second].insert(first);
		ss.clear();
	}

	for (auto& reportedSet : reportMap) {
		if (reportedSet.second.size() >= k) {
			for (auto& set_it : reportedSet.second)
				answer[idxMap[set_it]]++;
		}
	}
	return answer;
}

int main() {
	vector<int> ans;
	vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
	vector<string> report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
	int k = 2;

	ans = solution(id_list, report, k);

	for (auto c : ans) {
		cout << c << " ";
	}
}