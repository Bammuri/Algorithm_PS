#include <iostream>
#include <deque>
#include <string>
using namespace std;
int N,num;

deque <int> q;

void go(string &str) {

	if (str == "push") {
		q.push_back(num);
	}
	else if (str == "pop") {
		if (!q.empty()) {
			cout << q.front() << "\n";
			q.pop_front();
		}
		else {
			cout << "-1" << "\n";
		}
	}
	else if (str == "size") {
		cout << q.size() << "\n";
	}
	else if (str == "empty") {
		cout << q.empty() << "\n";
	}
	else if (str == "front") {
		if (!q.empty()) {
			cout << q.front() << "\n";

		}
		else {
			cout << "-1" << "\n";
		}
	}
	else if (str == "back") {
		if (!q.empty()) {
			cout << q.back() << "\n";
		}
		else {
			cout << "-1" << "\n";
		}

	}



}




int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;

		if (str == "push") {
			cin >> num;
			go(str);
		}
		else {
			go(str);
		}



	}


	return 0;
}