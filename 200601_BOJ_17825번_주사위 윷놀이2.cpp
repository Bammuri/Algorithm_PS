//1535 TC AC
//1554map 작성오류, map에서 1,2,3중복체크인덱스오류
#include <iostream>
#include <vector>
using namespace std;

typedef struct lo{
	int x, y;
}lo;


int val[10];
int map[4][30] = {
	{-1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
	{10,13,16,19,25,30,35,40},
	{20,22,24,25,30,35,40},
	{30,28,27,26,25,30,35,40}
};
int ans;

vector <lo> mal;
int order[10];


void checkIdx(int idx)
{
	if (mal[idx].x == 0 && mal[idx].y == 5)
		mal[idx] = { 1, 0 };
	else if (mal[idx].x == 0 && mal[idx].y == 10)
		mal[idx] = { 2, 0 };
	else if (mal[idx].x == 0 && mal[idx].y == 15)
		mal[idx] = { 3, 0 };	
	else if (mal[idx].x == 1 && mal[idx].y == 0)
		mal[idx] = { 0, 5 };
	else if (mal[idx].x == 2 && mal[idx].y == 0)
		mal[idx] = { 0, 10 };
	else if (mal[idx].x == 3 && mal[idx].y == 0)
		mal[idx] = { 0, 15 };
}

bool check_overlap(int t)
{
	int tx = mal[t].x;
	int ty = mal[t].y;
	for (int i = 0; i < mal.size(); i++)
	{
		if (t == i || map[mal[i].x][mal[i].y] == 0)continue;
		int rx = mal[i].x;
		int ry = mal[i].y;
		if (tx == rx && ty == ry) return true;
		if (tx > 0 && ty > 2 && rx > 0 && ry > 2 && map[tx][ty] == map[rx][ry])return true;
		if (map[tx][ty] == 40 && map[tx][ty] == map[rx][ry])return true;
	}

	return false;
}

void print_order()
{
	for (int i = 0; i < 10; i++)
		cout << order[i] << " ";
	cout << "\n";
}

void pickMal(int d, int s)
{
	//cout << d << " " << s << "\n";
	if (d == 10)
	{
		if (ans < s){
			print_order();
			ans = s;
		}
		return;
	}

	
	for (int i = 0; i < mal.size(); i++)
	{
		if (map[mal[i].x][mal[i].y] == 0)continue;

		mal[i].y += val[d];
		checkIdx(i);

		if (check_overlap(i)){
			checkIdx(i);
			mal[i].y -= val[d];
			continue;
		}
		order[d] = i+1;
		pickMal(d + 1, s + map[mal[i].x][mal[i].y]);

		checkIdx(i);
		mal[i].y -= val[d];
	}

	if (mal.size() < 4){
		int nidx = mal.size();
		mal.push_back({ 0, 0 });
		mal[nidx].y += val[d];
		checkIdx(nidx);
		if (!check_overlap(nidx)){
			order[d] = nidx+1;
			pickMal(d + 1, s + map[mal[nidx].x][mal[nidx].y]);
		}
		mal.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 10; i++)
		cin >> val[i];

	pickMal(0,0);

	cout << ans;

	return 0;
}