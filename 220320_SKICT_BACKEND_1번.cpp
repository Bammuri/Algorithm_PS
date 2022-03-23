#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

vector<string> g_goods;


int checkOtherStr(const string& tar,int tarIdx) {

	for (int i = 0; i < g_goods.size(); i++) {
		if (i == tarIdx) continue;
		if (g_goods[i].find(tar) != string::npos) {
			return 1;
		}

	}
	return 0;
}



vector<string> answer(vector<string>& goods) {
	vector<string> result;

	for (auto str : goods) 
		g_goods.push_back(str);
	


	for (int i  = 0; i < goods.size() ; i++) {
		string str = goods[i];
		string ans = "";
		set<string> ans_set;
		bool ansAppear = false;
		for (int strLen = 1; strLen <= str.length(); strLen++) {

			for (int startIdx = 0; startIdx <= str.length() - strLen; startIdx++) {
				
				if (!checkOtherStr(str.substr(startIdx, strLen), i)) {
					
					ans_set.insert(str.substr(startIdx, strLen));
					ansAppear = true;
				}
			}
			if (ansAppear) break;
		}
		
		for (auto str : ans_set) {
			ans += str;
			ans += " ";
		}
		if (ans!="")
			ans.erase(ans.end() - 1);
		
		if (ans == "")
			result.push_back("None");
		else
			result.push_back(ans);
	}


	return result;
}

int main()
{

	vector<string> goods = { "pencil","cilicon","contrabase","picturelist" };
	vector<string> goods1 = { "abcdeabcd","cdabe","abce","bcdeab" };
	vector<string> result;

	result = answer(goods1);

	for (auto str : result) {
		cout << str << "|\n";
	}

}