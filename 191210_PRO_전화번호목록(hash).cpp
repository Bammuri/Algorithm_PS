#include <string>
#include <vector>
#include <cstring>

using namespace std;
bool answer;
class Trie
{
public:
	Trie* next[10];
	bool is_next;
	bool is_finish;

	Trie()
	{
		is_next = false;
		is_finish = false;
		memset(next, 0, sizeof(next));
	}

	~Trie(){
		for (int i = 0; i<10; i++){
			if (next[i])
				delete next[i];
		}
	}

	void insert(string str)
	{
		if (str.size() == 0)
		{
			is_finish = true;
			if (is_finish == is_next) // 1195524421 119 순으로 나오는 경우
				answer = false;
			return;
		}
		int next_num = str[0] - '0';

		if (next[next_num] == 0)
		{
			next[next_num] = new Trie;
			is_next = true;
			if (is_finish == true){ // 119 1195524421 순으로 나오는 경우
				answer = false;
				return;
			}
		}

		next[next_num]->insert(str.substr(1, str.size() - 1));
	}
};

bool solution(vector<string> phone_book) {
	answer = true;

	Trie *root = new Trie;

	for (string phone_num : phone_book)
	{
		root->insert(phone_num);
		if (!answer) break;
	}

	return answer;
}