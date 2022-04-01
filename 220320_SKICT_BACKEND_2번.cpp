#include <string>
#include <deque>
#include <sstream>
#include <queue>
#include <iostream>

using namespace std;

struct process {
	string exeType;
	string arrTime;
	string exeTime, sIdx, eIdx, change;

	bool operator<(const process& rhs) const
	{
		if (exeType != rhs.exeType)
		{
			return exeType < rhs.exeType;
		}

		return arrTime > rhs.arrTime;
	}

};

deque <process> myProcesses;
priority_queue <process> waitProcesses;
vector<string> gArr;


struct runP {
	string exeType;
	int run;
	int exeTime;
};


void findProcess(runP& runProcess, vector<string>& answer)
{
	process targetProcess = waitProcesses.top();//pop()
	if (runProcess.run && runProcess.exeType == "read") {
		if (targetProcess.exeType == "write") return;

		runProcess.exeTime = runProcess.exeTime > stoi(targetProcess.exeTime)
			? runProcess.exeTime : stoi(targetProcess.exeTime);
		int sIdx = stoi(targetProcess.sIdx);
		int eIdx = stoi(targetProcess.eIdx);

		string tans;
		for (int i = sIdx; i <= eIdx; i++)
			tans += gArr[i];
		answer.push_back(tans);

		waitProcesses.pop();
		if (!waitProcesses.empty())
			findProcess(runProcess, answer);

	}
	else if (!runProcess.run) {
		if (targetProcess.exeType == "write") {
			runProcess.exeType = "write";
			runProcess.exeTime = stoi(targetProcess.exeTime);
			int sIdx = stoi(targetProcess.sIdx);
			int eIdx = stoi(targetProcess.eIdx);

			string change = targetProcess.change;
			for (int i = sIdx; i <= eIdx; i++)
				gArr[i] = change;

			waitProcesses.pop();

			runProcess.run = 1;
		}
		else if (targetProcess.exeType == "read") {

			runProcess.exeType = "read";
			runProcess.exeTime = runProcess.exeTime > stoi(targetProcess.exeTime)
				? runProcess.exeTime : stoi(targetProcess.exeTime);
			int sIdx = stoi(targetProcess.sIdx);
			int eIdx = stoi(targetProcess.eIdx);

			string tans;
			for (int i = sIdx; i <= eIdx; i++)
				tans += gArr[i];
			answer.push_back(tans);

			waitProcesses.pop();
			if (!waitProcesses.empty())
				findProcess(runProcess, answer);
			runProcess.run = 1;
		}

	}
}

vector<string> solution(vector<string>& arr, vector<string>& processes) {
	vector<string> answer;
	for (int i = 0; i < arr.size(); i++)
		gArr.push_back(arr[i]);

	for (string& proc : processes) {
		stringstream ss(proc);
		process p;

		ss >> p.exeType >> p.arrTime >> p.exeTime >> p.sIdx >> p.eIdx >> p.change;
	
		myProcesses.push_back(p);
	}

	int time = 0, exeTime = 0;
	runP runProcess;
	runProcess.exeTime = 0;
	while (!myProcesses.empty() || runProcess.run) {
		if (runProcess.exeTime == 0) {
			runProcess.run = 0;
			runProcess.exeType = "";
		}
		if (!myProcesses.empty()) {
			process nxtProc = myProcesses.front();
			if (stoi(nxtProc.arrTime) == time) {
				myProcesses.pop_front();
				waitProcesses.push(nxtProc);
			}
		}

		if (!waitProcesses.empty()) {
			findProcess(runProcess, answer);
		}

		//cout<<time<<" "<<exeTime<<" "<<runProcess.exeTime<<" "<<runProcess.run<<" "<<runProcess.exeType<<" "<<waitProcesses.size()<<"\n";
		if (runProcess.run) {
			exeTime++;
			runProcess.exeTime--;
		}
		time++;

	}

	answer.push_back(to_string(exeTime));


	return answer;
}

int main()
{
	vector <string> arr = { "1", "2", "4", "3", "3", "4", "1", "5" };
	vector<string> pro = { "read 1 3 1 2", "read 2 6 4 7", "write 4 3 3 5 2", "read 5 2 2 5", "write 6 1 3 3 9", "read 9 1 0 7" };
	vector <string> arr1 = { "1", "1", "1", "1", "1", "1", "1" };
	vector<string> pro1 ={"write 1 12 1 5 8", "read 2 3 0 2", "read 5 5 1 2", "read 7 5 2 5", "write 13 4 0 1 3", "write 19 3 3 5 5", "read 30 4 0 6", "read 32 3 1 5"};

	vector <string> answer;
	answer = solution(arr1, pro1);
	for (auto str : answer) {
		cout << str << " ";
	}
	

}