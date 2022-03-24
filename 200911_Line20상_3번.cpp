#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string road, int n) {
	int answer = 0;
	int zero_cnt = n;
	int left = 0;
	bool exe_flag = false;
	for (int right = 0; right < road.size(); right++){
		
		if (road[right] == '0'){
			if (zero_cnt > 0)
			{
				zero_cnt--;
			}
			else if (zero_cnt == 0)
				exe_flag = true;
		}

		if (exe_flag)
		{

			if (answer == 0)
			{
				answer = right;
			}
			else if (answer < right - left)
			{
				answer = right - left;
			}

			for (; left < road.size(); left++)
			{
				if (road[left] == '0')
				{
					zero_cnt++;
					left++;
					break;
				}
			}
			right--;
			exe_flag = false;
		}
	}

	if (answer == 0 && zero_cnt >= 0)
		answer = road.size();
	return answer;
}

int main()
{
	string road = "111011110011111011111100011111";
	cout << solution(road, 3);
	road = "001100";
	cout << solution(road, 5);

}