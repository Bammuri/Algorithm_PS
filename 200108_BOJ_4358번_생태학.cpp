#include <iostream>
#include <map>
#include <string>
using namespace std;

map < string, double > m;

int main() {

	string str;

	getline(cin, str);

	while (str != "") {
		m[str]++;
		getline(cin, str);
	}
	int sm = 0;
	for (auto pair : m) {
		sm += pair.second;
	}

	//for (auto pair : m) {

	//cout << pair.first << " " << pair.second << "\n";
	//}


	for (auto pair : m) {
		m[pair.first] = pair.second*100.0 / sm;
	}
	cout << fixed;
	cout.precision(4);
	for (auto pair : m) {
	cout << pair.first << " " << pair.second << "\n";
	}

	return 0;

}