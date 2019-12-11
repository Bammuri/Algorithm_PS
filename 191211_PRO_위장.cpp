#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map <string, int> hash;

	for (vector<string> pair : clothes) {
		hash[pair[1]]++;
	}

	unordered_map <string, int>::iterator iter;
	for (iter = hash.begin(); iter != hash.end(); iter++) {
		answer *= iter->second + 1;
	}

	return answer - 1;
}