#include <iostream>
#include <string>
#include <list>
#include <cmath>
#define MAX 1000000000
#define ll long long
using namespace std;

list <string> lst;
list <ll> int_lst;
ll num_lst[100001], numIdx;
bool eflag = false;
ll N, num, idx;

void goex(string origin_str) {

	string str = origin_str.substr(0, 3);

	if (str == "POP") {
		if (int_lst.size() < 1) {
			eflag = 1;
			return;
		}
		int_lst.pop_back();
	}
	else if (str == "INV") {
		if (int_lst.size() < 1) {
			eflag = 1;
			return;
		}
		auto iter = int_lst.end();
		iter--;
		ll tmp = *iter;
		int_lst.pop_back();

		int_lst.push_back(-1 * tmp);
	}
	else if (str == "DUP") {
		if (int_lst.size() < 1) {
			eflag = 1;
			return;
		}
		auto iter = int_lst.end();
		iter--;
		ll tmp = *iter;
		int_lst.push_back(tmp);

	}
	else if (str == "SWP") {
		if (int_lst.size() < 2) {
			eflag = 1;
			return;
		}
		auto iter = int_lst.end();
		iter--;
		ll tmp1 = *iter;
		iter--;
		ll tmp2 = *iter;
		int_lst.pop_back();
		int_lst.pop_back();

		int_lst.push_back(tmp1);
		int_lst.push_back(tmp2);

	}
	else if (str == "ADD") {
		if (int_lst.size() < 2) {
			eflag = 1;
			return;
		}
		auto iter = int_lst.end();
		iter--;
		ll tmp1 = *iter;
		iter--;
		ll tmp2 = *iter;

		int_lst.pop_back();
		int_lst.pop_back();

		ll result = tmp1 + tmp2;

		if (abs(result)>MAX) {
			eflag = 1;
			return;
		}
		else
			int_lst.push_back(result);

	}
	else if (str == "SUB") {
		if (int_lst.size() < 2) {
			eflag = 1;
			return;
		}
		auto iter = int_lst.end();
		iter--;
		ll tmp1 = *iter;
		iter--;
		ll tmp2 = *iter;

		int_lst.pop_back();
		int_lst.pop_back();

		ll result = tmp2 - tmp1;

		if (abs(result)>MAX) {
			eflag = 1;
			return;
		}
		else
			int_lst.push_back(result);

	}
	else if (str == "MUL") {
		if (int_lst.size() < 2) {
			eflag = 1;
			return;
		}
		auto iter = int_lst.end();
		iter--;
		ll tmp1 = *iter;
		iter--;
		ll tmp2 = *iter;

		int_lst.pop_back();
		int_lst.pop_back();

		ll result = tmp1* tmp2;
		if (abs(result)>MAX) {
			eflag = 1;
			return;
		}
		else
			int_lst.push_back(result);

	}
	else if (str == "DIV") {
		if (int_lst.size() < 2) {
			eflag = 1;
			return;
		}
		auto iter = int_lst.end();
		iter--;
		ll tmp1 = *iter;
		iter--;
		ll tmp2 = *iter;

		if (tmp1 == 0) {
			eflag = 1;
			return;
		}

		int_lst.pop_back();
		int_lst.pop_back();

		ll result = tmp2 / tmp1;

		if (abs(result)>MAX) {
			eflag = 1;
			return;
		}
		else
			int_lst.push_back(result);

	}
	else if (str == "MOD") {
		if (int_lst.size() < 2) {
			eflag = 1;
			return;
		}
		auto iter = int_lst.end();
		iter--;
		ll tmp1 = *iter;
		iter--;
		ll tmp2 = *iter;


		if (tmp1 == 0) {
			eflag = 1;
			return;
		}

		int_lst.pop_back();
		int_lst.pop_back();

		ll result = tmp2%tmp1;

		if (abs(result)>MAX) {
			eflag = 1;
			return;
		}
		else
			int_lst.push_back(result);

	}
	else if (str == "NUM") {

		int_lst.push_back(num_lst[idx++]);

	}




}

void doit() {


	for (auto iter = lst.begin(); iter != lst.end(); iter++) {

		eflag = false;
		goex(*iter);
		if (eflag) {

			cout << "ERROR\n";
			return;
		}
	}
	//cout <<idx<<" "<< num << "\n";

	if (int_lst.size() == 1)
		cout << int_lst.back() << "\n";
	else
		cout << "ERROR\n";
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str = "";
	while (str != "QUIT") {

		int_lst.clear();
		numIdx = 0;
		lst.clear();


		if (str != "") {
			if (str == "NUM") {
				ll num = 0;
				cin >> num;
				num_lst[numIdx++] = num;
			}

			if (str != "END")
				lst.push_back(str);
		}


		while (str != "END") {

			cin >> str;

			if (str == "NUM") {
				ll num = 0;
				cin >> num;
				num_lst[numIdx++] = num;
			}

			if (str != "END")
				lst.push_back(str);
		}

		N, num = 0;
		cin >> N;

		while (N--) {
			int_lst.clear();
			idx = 0;
			cin >> num;

			int_lst.push_back(num);
			doit();

		}
		cout << "\n";
		cin >> str;
	}






	return 0;
}