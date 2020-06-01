//2135
//2345  중복순열 문제, 각 말의 위치를 더하고 바꾸고 바꾸고 빼고, 
//끝남의 표시,맵이 분열되어 안겹치는부분 따로 명시
#include <iostream>
#include <vector>
using namespace std;

typedef struct lo
{
	int x, y;
};

int pan[4][30] = 
{ { -1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
{ 10, 13, 16, 19, 25, 30, 35, 40},
{ 20, 22, 24, 25, 30, 35, 40},
{ 30, 28, 27, 26, 25, 30, 35, 40} };
int val[10];
int ans;
vector <lo> mal_lo(5); //말의 위치
int order[10];

bool is_full_mal(int i)
{
	int x = mal_lo[i].x;
	int y = mal_lo[i].y;
	int val = pan[x][y];
	for (int idx = 1; idx <= 4; idx++)
	{
		int idx_val = pan[mal_lo[idx].x][mal_lo[idx].y];
		if (idx == i) continue;
		if (idx_val != 0 && mal_lo[idx].x == x && mal_lo[idx].y == y) return true;
		if (idx_val != 0 && x > 1 && y > 2 && idx_val == val)return true;
		if (val == 40 && idx_val == val)return true;
	}
	return false;
}

void checkChange(int i)
{
	if (mal_lo[i].x == 0 && mal_lo[i].y == 5)
		mal_lo[i] = { 1, 0 };
	else if (mal_lo[i].x == 0 && mal_lo[i].y == 10)
		mal_lo[i] = { 2, 0 };
	else if (mal_lo[i].x == 0 && mal_lo[i].y == 15)
		mal_lo[i] = { 3, 0 };
	else if (mal_lo[i].x == 1 && mal_lo[i].y == 0)
		mal_lo[i] = { 0, 5 };
	else if (mal_lo[i].x == 2 && mal_lo[i].y == 0)
		mal_lo[i] = { 0, 10 };
	else if (mal_lo[i].x == 3 && mal_lo[i].y == 0)
		mal_lo[i] = { 0, 15 };
}

void print_order()
{
	for (int i = 0; i < 10; i++)
		cout << order[i] << " ";
	cout << "\n";
}


void pickMal(int d, int v)
{
	if (d == 10){
		if (ans <= v){
			print_order();
			ans = v;
		}
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		if (pan[mal_lo[i].x][mal_lo[i].y]==0)  continue;

		mal_lo[i].y += val[d];
		checkChange(i);

		if (is_full_mal(i)){
			checkChange(i);
			mal_lo[i].y -= val[d];
			continue;
		}
		order[d] = i;
		pickMal(d + 1, v + pan[mal_lo[i].x][mal_lo[i].y]);

		checkChange(i);
		mal_lo[i].y -= val[d];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 10; i++)
		cin >> val[i];

	pickMal(0, 0);
	cout << ans;
	return 0;
}