#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	// order 미리 정렬해두기
	for (string& order : orders) sort(order.begin(), order.end());
	for (int c : course) {
		map<string, int> m;
		for (string order : orders) {
			if (order.length() > c) {
				vector<bool> comb(order.length() - c, false);
				for (int i = 0; i < c; ++i) comb.push_back(true);

				// do-while & next_permutation으로 조합 구하기
				do {
					string temp = "";
					for (int i = 0; i < order.length(); ++i) {
						if (comb[i]) temp += order[i];
					}

					m[temp]++;
				} while (next_permutation(comb.begin(), comb.end()));
			}
			else if (order.length() == c) m[order]++;
		}

		// 가장 많이 주문된 조합 찾기
		int max_val = max_element(m.begin(), m.end(),
			[](const pair<string, int>& a, const pair<string, int>& b) {
				return a.second < b.second;
			})->second;
		if (max_val < 2) continue;
		for (auto iter : m) {
			if (iter.second == max_val) {
				answer.push_back(iter.first);
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}
int main() {
	vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2,3,4 };
	vector <string> answer = solution(orders, course);

	for (auto str : answer)
		cout << str << " ";
}