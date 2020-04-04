#include <iostream>
#include <vector>
#include <map>
using namespace std;

map <int, int> m;

void go(int &lo, int &n, int start){
	if (lo > 28 && (m[5] || m[10])){
		lo = 0;
		return;
	}
	else if (lo > 19 && (m[15])){
		lo = 0;
		return;
	}
	else if (start != 1 && lo == 0)
		return;
	if (n != -1){
		if (lo == 5){
			m[5] = 1;
			lo = 19 + n;
			if (lo == 22)
				m[22] = 21;
			else if (lo == 15)
				m[15] = 24;
		}
		else if (lo == 10){
			m[10] = 1;
			if (n == 3)
				lo = 22;
			else if (n > 3)
				lo = 23 + n;
			else 
				lo = 24 + n;
			m[22] = 26;
			
		}
		else if (lo == 22){
			lo = 26 + n;
		}
		else if (lo >= 20 && lo <= 24){
			lo += n;
			if (lo > 24){
				lo = 14 + (lo - 24);
				m[15] = 24;
				m[22] = 21;
			}
			else if (lo == 22)
				m[22] = 21;
		}
		else if (lo >= 25 && lo < 28){
			lo += n;
			if (lo == 27){
				lo = 22;
				m[22] = 26;
			}
			else if (lo > 27){
				lo--;
				m[22] = 26;
			}
		}
		else{
			lo += n;
			if (lo == 15)
				m[15] = 14;
		}
	}
	else{
		if (lo == 20)
			lo = 5;
		else if (lo == 25)
			lo = 10;
		else if (lo == 27)
			lo = 22;
		else if (lo == 22){
			lo = m[22];
			m[22] = 0;
		}
		else if (lo == 15){
			lo = m[15];
			m[15] = 0;
		}
		else
			lo -= 1;
	}

	cout << lo << " ";

}


int solution(vector <int> &input){
	int lo = 0;
	int start = 1;
	for (auto n : input){
		go(lo, n, start);
		if (start == 1)
			start = 0;
	}
	
	return lo;
}

int main(){
	vector <int> input = { 1, -1 };
	cout << solution(input)<<"\n";
	input = { 1, -1, 3 };
	cout << solution(input) << "\n";
	input = { 4, 1, 3, 1 };
	cout << solution(input) << "\n";
	input = { 5, 3, 1, -1, -1 };
	cout << solution(input) << "\n";
	input = { 4, 4, 2, 4, -1, -1 };
	cout << solution(input) << "\n";
	m.clear();
	input = { 5, 2, 5, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-1,-1 };
	cout << solution(input) << "\n";
	return 0;
}