#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int sie;

bool next(int x, int y, bool star, vector<string> &drum) {
		//cout<<x<<" "<<y<<'\n';
		if (x + 1 == sie)
			return true;
		switch (drum[x][y]) {
		case '#':
				return next( x + 1, y, star, drum);
		case '>':
				return next( x, y + 1, star, drum);
		case '<':
				return next(x, y - 1, star, drum);
		case '*':
				if (star) return false;
				return next(x + 1, y, true, drum);
		}
}

int solution(vector<string> drum) {
		int answer = 0;

		sie = drum.size();
		for (unsigned int i = 0; i<drum[0].size(); i++) {
				answer += next(0, i, false, drum) ? 1 : 0;
		}
		return answer;
}

int main() {
	vector <string>ex = { "######",">#*###","####*#","#<#>>#",">#*#*<","######" };
	cout<<solution(ex);
	return 0;
}

/*
######
>#*###
####*#
#<#>>#
>#*#*<
######
*/