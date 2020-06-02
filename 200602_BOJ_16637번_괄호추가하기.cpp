//1130 TCAC 
//1200 답이 음수가 나올수 있음, 답이 int형이라도 중간에 long long으로 계산가능
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int N,visit[9];
string s;
vector <long long> onum;
vector <char> ooper;
long long ans = -1e9;


void calcul(int idx,vector <char>&oper,vector <long long> &num){
	char ch = oper[idx];
	long long first = num[idx];
	long long second = num[idx + 1];
	long long res;

	if (ch == '-'){
		res = first - second;
	}
	else if (ch == '+'){
		res = first + second;
	}
	else if (ch == '*'){
		res = first * second;
	}
	
	oper.erase(oper.begin() + idx);
	num[idx] = res;
	num.erase(num.begin() + idx + 1);
}

void print_visit()
{
	for (int i = 0; i < N / 2; i++){
		cout << visit[i];
	}
	cout << "\n";
}

void calcul()
{
	//print_visit();
	vector <long long> num(onum);
	vector <char> oper(ooper);
	for (int i = 0; i < oper.size(); i++){
		int nidx = i + ((N / 2) - oper.size());
		if (visit[nidx]){
			calcul(i, oper, num);
			i--;
		}
	}
	int m = oper.size();
	for (int i = 0; i < m; i++){
		calcul(0, oper, num);
	}

	if (ans < num[0])
		ans = num[0];
}


void get_order(int d)
{

	calcul();

	if (N / 4 == d) return;

	for (int i = 0; i < N/2; i++){
		if (visit[i])continue;
		if (i - 1 >= 0 && visit[i - 1])continue;
		if (i + 1 < N/2 && visit[i + 1])continue;
		visit[i] = 1;
		get_order(d + 1);
		visit[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> s;

	for (int i = 0; i < N; i++){
		if (i % 2) ooper.push_back(s[i]);
		else onum.push_back(s[i] - '0');
	}

	get_order(0);

	cout << ans;
	return 0;
}