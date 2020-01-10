#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
string n;
int arr[100001];
int main() {
	cin >> n;


	int idx = 0;
	for (auto c : n) {
		arr[idx++] = c - '0';
	}

	sort(arr, arr + idx, greater<int>());
	bool zero = false;

	int sm = 0;
	for (int i = 0; i < idx; i++) {
		if (arr[i] == 0)zero = true;
		//cout << arr[i];
		sm += arr[i];
	}
	while(1){
		if (zero == true && sm % 3 == 0) {
			for (int i = 0; i < idx; i++) {
				cout << arr[i];
			}
			break;
		}
		else {
			cout << "-1";
			break;
		}
		
	}
	return 0;
}