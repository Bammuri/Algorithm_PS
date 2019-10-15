//문제 제대로 이해하기 절대 급하지말자..
//입력 1오류
//3시간
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
string ans;
int num = 1;

int solution(string s) {
	int size = s.size();
	int min = 1000;
	if (size == 1)min = 1;
	for (int tok = 1; tok <= size / 2; ++tok){
		string sample, can;
		ans = "";
		for (int idx = 0; idx<size; idx += tok){
			sample = "", can = "";
			for (int l = idx; l<idx + tok; l++){
				if (l<size)sample += s[l];
			}
			for (int l = idx + tok; l<tok + idx + tok; l++){
				if (l<size)can += s[l];
			}

			if (sample.compare(can) == 0){
				num++;
				if (idx == size - tok){
					ans += to_string(num);
					ans += sample;
					num = 1;
				}
			}
			else {
				if (num != 1)ans += to_string(num);
				ans += sample;
				num = 1;
			}


		}
		// cout<<ans<<" "<<ans.size()<<endl;
		int tmp = ans.size();
		if (min>tmp) min = tmp;
	}


	int answer = min;
	return answer;
}