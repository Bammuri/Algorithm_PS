#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;
//fee  기본시간(분) 기본요금(원) 단위시간(분) 단위요금(원)
//record 시각HH:MM 차량번호0000 내역IN/OUT 

class lo {
public:
	int enterTime,Isout;
	int totalTime;
};

map <string, lo> carMap;
vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	for (string str : records) {
		stringstream ss(str);
		string time, carNum, inout;
		ss >> time >> carNum >> inout;

		int timeI = (stoi(time.substr(0, 2)) * 60) + stoi(time.substr(3, 2));

		if (inout == "IN") {
			if (carMap.find(carNum) == carMap.end()) {
				carMap[carNum] = { timeI, 0, 0 };
				continue;
			}
			carMap[carNum].enterTime = timeI;
			carMap[carNum].Isout = 0;
		}
		else if(inout == "OUT"){
			carMap[carNum].totalTime += (timeI - carMap[carNum].enterTime);
			carMap[carNum].Isout = 1;
		}
	}

	for (auto iter : carMap) {
		int time = iter.second.totalTime;
		int ans = 0;
		if (!iter.second.Isout) 
			time = (23 * 60 + 59 - iter.second.enterTime)+ time;

		ans = (fees[0] < time) ? fees[1] + (ceil(((time - fees[0]) / (double)fees[2])) * fees[3]) : fees[1];
		answer.push_back(ans);
	}
	return answer;
}

int main() {
	vector<int> fees = {180, 5000, 10, 600};
	vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
	vector<int> ans = solution(fees, records);
	for (auto i : ans) {
		cout << i << " ";
	}
	return 0;
}