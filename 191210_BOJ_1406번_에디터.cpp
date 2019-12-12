#include <iostream>
#include <string>
#include <list>
using namespace std;

list <char> l;
list <char>::iterator iter;

void doit(char &ch){
	switch (ch){
	case 'L':
		if (iter != l.begin()){
			iter--;
		}
		break;
	case 'D':
		if (iter != l.end()){
			iter++;
		}
		break;
	case 'B':
		if (iter != l.begin()){
			iter--;
			l.erase(iter++);
		}
		break;
	case 'P':
		char what;

		cin >> what;

		l.insert(iter, what);

		break;

	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);


	string input;
	cin >> input;

	for (char a : input)
		l.push_back(a);

	iter = l.end();

	int order_num = 0;

	cin >> order_num;

	for (int i = 0; i < order_num; i++){
		char ch;

		cin >> ch;

		doit(ch);

	}


	for (char ch : l){
		cout << ch;
	}


	return 0;
}