#include <iostream>
#include <vector>
using namespace std;

int solution(vector <int> &input){
	int mx = 0;
	int ans = 0;

	for (int &n : input)
		if (n > mx)
			mx = n;
	
	for (int i = 1; i <= mx; i++){
		bool cnt_flag = 0;
		int cnt = 0;
		for (int &n : input){

			if (i <= n && !cnt_flag)
				cnt_flag = 1;
			else if (cnt_flag && i > n)
				cnt++;
			else if (cnt_flag && i <= n){
				ans += cnt;
				cnt = 0;
			}
		}
	}
	return ans;
}


int main(){
	vector <int> v = { 1, 2, 1, 3, 1, 2, 1, 3 };
	cout << solution(v)<<"\n";
	v = { 1, 5, 0, 0, 0, 0, 0, 5, 6, 6 };
	cout << solution(v) << "\n";
	v = { 1, 4, 3, 2, 1, 1, 0, 0 };
	cout << solution(v) << "\n";
}