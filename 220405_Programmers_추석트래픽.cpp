#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class ScheduledTime {
public:
	int startT, endT;
};

vector <ScheduledTime> scheduled;

int solution(vector<string> lines) {
	int answer = 0;

	for (auto str : lines) {
		string Time = str.substr(11, 12);
		string duration = str.substr(24);
		duration.erase(duration.end() - 1);

		int endTime = (((stoi(Time.substr(0, 2)) * 3600) + (stoi(Time.substr(3, 2)) * 60) + stoi(Time.substr(6, 2))) * 1000)
			+ stoi(Time.substr(9,3));

		int durationTime = (stod(duration) * 1000);

		int startTime = endTime - durationTime + 1;
		//cout << startTime << " " << endTime << "\n";
		scheduled.push_back({startTime, endTime});
	}



	for (int i = 0; i < scheduled.size();i++) {
		int startTime = scheduled[i].endT;
		int endTime = scheduled[i].endT + 999;
		int thres = 0;

		for (int k = 0; k < scheduled.size(); k++) {
			if (scheduled[k].startT <= endTime && scheduled[k].endT >= startTime)
				thres++;
		}
		answer = max(answer, thres);
	}

	return answer;
}

int main() {
	vector<string> lines = { "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s",
		"2016-09-15 20:59:58.299 0.8s","2016-09-15 20:59:58.688 1.041s","2016-09-15 20:59:59.591 1.412s",
		"2016-09-15 21:00:00.464 1.466s","2016-09-15 21:00:00.741 1.581s","2016-09-15 21:00:00.748 2.31s",
		"2016-09-15 21:00:00.966 0.381s","2016-09-15 21:00:02.066 2.62s" };
	cout << solution(lines);
	return 0;
}