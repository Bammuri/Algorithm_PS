#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int isPrime(int num) {
	if (num == 1||num ==0)
		return 0;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}

int solution(int n, int k) {
	int answer = 0;
	string restr="";

	do {
		
		restr += to_string(n % k);
		n /= k;
		
	} while (n >= k);

	restr += to_string(n);

	reverse(restr.begin(), restr.end());


	for (int s = 0; s < restr.length(); ) {
		for (int len = 1; len + s <= restr.length(); len++) {
			if (s + len == restr.length()||(s+len<restr.length()&&restr[s + len] == '0')) {
				//cout << restr.substr(s, len) << "\n";
				if (isPrime(stoi(restr.substr(s, len)))) {
					answer++;
					
				}
				s = len + s + 1;
				break;
			}

		}
	
	}

	return answer;
}


int main() {
	cout << solution(7, 7);
	return 0;
}