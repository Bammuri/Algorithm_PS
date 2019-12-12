#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct myst{
	int sum;
	string s;
	bool operator< (const myst &c)const{
		return sum>c.sum;
	}
};

struct ans{
	int idx;
	int play;
	bool operator<(const ans &a)const{
		return play>a.play;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int size = genres.size();
	map <string, int> hash;
	vector <myst> vec;


	for (int i = 0; i < size; i++) {
		hash[genres[i]] += plays[i];
	}
	for (auto pair : hash) {
		vec.push_back({ pair.second, pair.first });
	}

	sort(vec.begin(), vec.end());

	for (auto my : vec){
		vector <ans> tmp;
		for (int i = 0; i<size; i++) {
			if (my.s == genres[i]){
				tmp.push_back({ i, plays[i] });
			}
		}

		sort(tmp.begin(), tmp.end());
		int cnt = 0;
		for (auto t : tmp){
			cnt++;
			if (cnt>2) break;
			answer.push_back(t.idx);

		}
	}



	return answer;
}