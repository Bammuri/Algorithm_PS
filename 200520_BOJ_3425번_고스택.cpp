//1345
//1435 초안완성 TC AC
// sub 구현 안함, mul 예외, error 로직 중복, 제수 피젯수 거꾸로
//1526 AC sub 숫자 위치 바뀜, long long 으로 abs넣어주기
#include <iostream>
#include <string>
#include <deque>
#include <cmath>
using namespace std;

#define LIMIT 1000000000
#define ll long long

deque <pair<string,int>> order;
deque <int> q;

bool calcul_each(string s, int n){


	if (s == "NUM"){
		q.push_back(n);
	}
	else if (s == "POP"){
		if (q.size() < 1)
			return true;
		q.pop_back();
	}
	else if (s == "INV"){
		if (q.size() < 1)
			return true;
		ll num = q.back();
		q.pop_back();
		num *= -1;
		q.push_back(num);
	}
	else if (s == "DUP"){
		if (q.size() < 1)
			return true;

		ll num = q.back();
		q.push_back(num);
	}
	else if (s == "SWP"){
		if (q.size() < 2)
			return true;
		ll first = q.back();
		q.pop_back();
		ll second = q.back();
		q.pop_back();
		q.push_back(first);
		q.push_back(second);
	}
	else if (s == "ADD"){
		if (q.size() < 2)
			return true;
		ll first = q.back();
		q.pop_back();
		ll second = q.back();
		q.pop_back();
		
		if (abs(first + second) > LIMIT)
			return true;

		q.push_back(first + second);
	}
	else if (s == "SUB"){
		if (q.size() < 2)
			return true;
		ll first = q.back();
		q.pop_back();
		ll second = q.back();
		q.pop_back();
		if (abs(second - first) > LIMIT)
			return true;

		q.push_back(second - first);
	}
	else if (s == "MUL"){
		if (q.size() < 2)
			return true;
		ll first = q.back();
		q.pop_back();
		ll second = q.back();
		q.pop_back();
		if (abs(first * second) > LIMIT)
			return true;

		q.push_back(first * second);
	}
	else if (s == "DIV"){
		if (q.size() < 2)
			return true;
		ll first = q.back();
		q.pop_back();
		ll second = q.back();
		q.pop_back();
		if (first == 0)
			return true;
		ll res = abs(second) / abs(first);

		if ((first * second < 0) || (second == 0 && first <0))
			res *= -1;
		
		q.push_back(res);
	}
	else if (s == "MOD"){
		if (q.size() < 2)
			return true;
		ll first = q.back();
		q.pop_back();
		ll second = q.back();
		q.pop_back();
		if (first == 0)
			return true;
		ll res = abs(second) % abs(first);

		if (second < 0)
			res *= -1;
		
		q.push_back(res);
	}
	return false;
}

void printstack(){
	cout << "\n";
	for (int i = 0; i < q.size(); i++)
	{
		cout<<q[i] << " ";
	}
	 
}
void calcul(int input)
{
	q.clear();
	q.push_back(input);
	bool flag = false;
	for (int i = 0; i < order.size(); i++)
	{
		if (flag = calcul_each(order[i].first, order[i].second)) break;
		//printstack();
	}
	if (q.size() != 1 || flag)
		cout << "ERROR\n";
	else
		cout << q.back() << "\n";

}

void sol(){
	string s;
	cin >> s;
	while (s != "QUIT")
	{
		order.clear();
		while (s != "END")
		{
			if (s != "NUM")
				order.push_back(make_pair(s,0));
			else
			{
				int n;
				cin >> n;
				order.push_back(make_pair(s, n));
			}

			cin >> s;
		}
		int many=0;

		cin >> many;

		for (int i = 0; i < many; i++)
		{
			int tmp;
			cin >> tmp;
			calcul(tmp);
		}
		cout << "\n";
		cin >> s;
	}



}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	sol();


	return 0;
}