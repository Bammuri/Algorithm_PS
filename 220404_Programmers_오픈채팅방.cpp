#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map <string, string> nameMap;

class tans{
public:
	string ac;
	string h;
};

vector<string> solution(vector<string> record) {
	string action, hash, name;
	vector <tans> tanswer;
	for (auto re : record) {
		stringstream ss(re);
		ss >> action >> hash >>name;
		if (action == "Enter") {
			nameMap[hash] = name;
			tanswer.push_back({ action,hash });
		} else if (action == "Leave") {
			tanswer.push_back({ action,hash });
		} else if (action == "Change") {
			nameMap[hash] = name;
		}
	}



	vector<string> answer;

	for (int i = 0; i < tanswer.size(); i++) {
		string realans = "";
		if (tanswer[i].ac == "Enter") {
			realans = nameMap[tanswer[i].h] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
		} else if (tanswer[i].ac == "Leave") {
			realans = nameMap[tanswer[i].h] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
		}
		answer.push_back(realans);
	}

	return answer;
}

int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	vector<string> ans = solution(record);
	for (string str : ans) {
		cout << str << "\n";
	}
	
}