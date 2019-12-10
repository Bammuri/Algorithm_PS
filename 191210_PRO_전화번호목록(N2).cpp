#include <string> 
#include <vector> 
#include <unordered_map> 
using namespace std; 
bool solution(vector<string> phone_book) { 
	for (string cand : phone_book) { 
		int cand_size = cand.size(); 
		
		for (string phone_num : phone_book) { 
			
			if (cand_size > phone_num.size() || cand==phone_num) continue;
			string sub_num = phone_num.substr(0,cand_size);
			if (cand.compare(sub_num) == 0) { 
				return false; 
			} 
		} 
	} 
	return true; 
}
