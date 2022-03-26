#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;


class lo {
public:
	string team_name, team_name_colon;
	string application_name, application_name_colon;
	string error_level, error_level_colon;
	string message, message_colon;
	string t, a, e, m;
};

lo l;

bool isBlankWrong(string& log) {
	if (log[0] != 't')
		return true;

	std::string::size_type n;

	n = log.find("team_name");
	string team = log.substr(n);
	if ((team[9] != ' ') || (team[10] != ':') || (team[11] != ' ') || (team[12] == ' ')) {

		return true;
	}

	n = log.find("application_name");
	string app = log.substr(n);
	if ((app[16] != ' ') || (app[17] != ':') || (app[18] != ' ') || (app[19] == ' ')) {

		return true;
	}

	n = log.find("error_level");
	string err = log.substr(n);
	if ((err[11] != ' ') || (err[12] != ':') || (err[13] != ' ') || (err[14] == ' ')) {

		return true;
	}


	n = log.find("message");
	string mes = log.substr(n);
	if ((mes[7] != ' ') || (mes[8] != ':') || (mes[9] != ' ') || (mes[10] == ' ')) {

		return true;
	}

	return false;
}


bool isAllWordCapOrSmall(string& str) {
	if (str.length() == 0)
		return true;


	for (auto c : str) {
		if ((c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z'))
			continue;
		return true;
	}

	return false;
}

int solution(vector<string> logs) {
	int answer = 0;

	for (auto& log : logs) {
		if (log.length() > 100) {
			answer++;
			continue;
		}

		stringstream ss(log);
		ss >> l.team_name >> l.team_name_colon >> l.t >> l.application_name >> l.application_name_colon >> l.a >> l.error_level >> l.error_level_colon >> l.e >> l.message >> l.message_colon >> l.m;

		if (l.team_name != "team_name" || l.application_name != "application_name" || l.error_level != "error_level" || l.message != "message") {
			answer++;
			continue;
		}

		if (l.team_name_colon != ":" || l.application_name_colon != ":" || l.error_level_colon != ":" || l.message_colon != ":") {
			answer++;
			continue;
		}

		if (isAllWordCapOrSmall(l.t) || isAllWordCapOrSmall(l.e) || isAllWordCapOrSmall(l.a) || isAllWordCapOrSmall(l.m)) {
			answer++;
			continue;
		}


		if (isBlankWrong(log)) {
			answer++;
			continue;
		}

	}



	return answer;
}


int main() {
	vector<string> logs = { "team_name : db application_name : dbtest error_level : info message : test" };

	cout << solution(logs);
}