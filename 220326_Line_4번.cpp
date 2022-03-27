#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> arr, vector<int> brr) {
	int answer = 0;

	for (int i = 0; i + 1 < arr.size(); i++) {

		if (arr[i] == brr[i]) continue;

		int sum = arr[i] + arr[i + 1];

		arr[i] = brr[i];
		arr[i + 1] = sum - brr[i];
		answer++;
	}


	return answer;
}

int main() {
	vector<int> arr = { 3, 7, 2, 4 };
	vector<int> brr = { 4, 5, 5, 2 };

	cout << solution(arr, brr);
}


