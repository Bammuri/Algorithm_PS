
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ADDPLAYER       (1)
#define REMOVEPLAYER    (2)
#define GETRANK         (3)
#define COUNTPLAYERS    (4)

#define MAX_NAME_LEN    (12)
#define EVENT_COUNT     (5)

///===== user.cpp =====

const int MAXS = (int)5e8;
const int LM = 50005;
const int SIZE = (1 << 17);
int hcnt, lcnt, N;

int strcomp(char a[], char b[])
{
	for (int i = 0; a[i] || b[i]; i++) if (a[i] != b[i])return 0;
	return 1;
}

struct Name {
	int score[6];
	char name[13];
	Name* next;
	Name* alloc(char _name[], Name* _next)
	{
		int i;
		for (i = 0; _name[i]; i++)name[i] = _name[i];
		name[i] = 0, next = _next;
		return this;
	}
} hashbuf[LM], *hash[20000];

Name* search(char name[])
{
	int id = (name[0] - 'a') * 676 +
		(name[1] - 'a') * 26 + (name[2] - 'a');
	for (Name* p = hash[id]; p; p = p->next)
		if (strcomp(name, p->name)) return p;
	return hash[id] = hashbuf[hcnt++].alloc(name, hash[id]);
}

int tree[6][SIZE];
struct Data {
	int val;
	Data* next;
	Data* alloc(int _val, Data* _next) {
		val = _val, next = _next;
		return this;
	}
} listbuf[LM * 6], * list[6][LM];

void update(int tree[], int node, int s, int e, int id, int mp)
{
	tree[node] += mp;
	if (s == e) return;
	int m = (s + e) / 2;
	if (id <= m) update(tree, node * 2, s, m, id, mp);
	else update(tree, node * 2 + 1, m + 1, e, id, mp);
}

int count(int tree[], int node, int ts, int te, int us, int ue)
{
	//printf("%d %d %d %d\n ", ts, te, us, ue);
	if (ts > ue || te < us)return 0;
	if (us <= ts && te <= ue)return tree[node];
	int m = (ts + te) / 2;
	return count(tree, node * 2, ts, m, us, ue)
		+ count(tree, node * 2 + 1, m + 1, te, us, ue);
}

/// 초기화 함수
void init()
{
	hcnt = lcnt = N = 0;
	for (int i = 0; i < 20000; i++)hash[i] = 0;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < SIZE; j++)tree[i][j] = 0;
		for (int j = 0; j < LM; j++)list[i][j] = 0;
	}
}

/// 데이터베이스에 선수와 5개 종목 점수를 추가
void addPlayer(char name[], int rscore[])
{ 
	Name* player = search(name);
	player->score[5] = 0;
	for (int i = 0; i < 5; i++){
		player->score[i] = rscore[i];
		player->score[5] += rscore[i];
	}
	for (int i = 0; i < 6; i++)
	{
		int id = player->score[i] / 2000;
		if (i == 5) id /= 5;
		update(tree[i], 1, 0, 50000, id, 1);
		list[i][id] = listbuf[lcnt++].alloc(player->score[i], list[i][id]);
	}

}

/// 데이터베이스에서 선수 이름이 name인 레코드를 삭제
void removePlayer(char name[])
{
	Name* player = search(name);
	for (int i = 0; i < 6; i++){
		int id = player->score[i] / 2000;
		if (i == 5) id /= 5;
		update(tree[i], 1, 0, 50000, id, -1);
		for (Data* p = list[i][id]; p;p = p->next){
			if (p->val == player->score[i]){
				p->val = -1;
				break;
			}
		}
	}
}

/// 입력으로 들어온 선수의 순위를 리턴
/// index = 0 ~ 4 : 해당 index 종목의 순위 리턴
/// index = 5     : 5개 종목 총합의 종합 순위 리턴
int getRank(char name[], int index)
{
	Name* player = search(name);
	int id = player->score[index] / 2000;
	if (index == 5) id /= 5;
	int rank = count(tree[index], 1, 0, 50000, id + 1, 50000);
	//printf("rank! %d\n ", rank);
	for (Data* p = list[index][id]; p; p = p->next){
		//printf("val %d\n ", p->val);
		if (p->val > player->score[index]) rank++;
	}
	return rank + 1;
}

/// lowScore이상 highScore이하 점수를 가진 선수 수 리턴
/// index = 0 ~ 4 : 해당 index 종목의 점수가 lowScore이상 highScore이하인 선수 수 리턴
/// index = 5     : 5개 종목 총합이 lowScore이상 highScore이하인 선수 수 리턴
int countPlayers(int lowScore, int highScore, int index)
{
	int lowid = lowScore / 2000, highid = highScore / 2000;
	if (index == 5) lowid /= 5, highid /= 5;
	int sum = count(tree[index], 1, 0, 50000, lowid, highid);
	//printf("sum! %d ",sum);
	for (Data* p = list[index][lowid]; p; p = p->next)
		if (p->val >= 0 && p->val < lowScore) sum--;
	for (Data* p = list[index][highid]; p; p = p->next)
		if (p->val > highScore) sum--;
	//printf("sum!!!!!!");
	return sum;
}



///===== main.cpp =====


void init();
void addPlayer(char name[], int rscore[]);
void removePlayer(char name[]);
int  getRank(char name[], int index);
int  countPlayers(int lowScore, int highScore, int index);
/////////////////////////////////////////////////////////////////////////

static int run(int Ans)
{
	int N;
	int inputCnt = scanf("%d", &N);
	if (inputCnt != 1) {
		return 0;
	}

	init();

	for (int i = 0; i < N; ++i)
	{
		int cmd;
		scanf("%d", &cmd);

		char s1[MAX_NAME_LEN + 1];
		int  score[EVENT_COUNT];
		int  x1, x2, x3, ret, ans;

		switch (cmd)
		{
		case ADDPLAYER:
			scanf("%s", s1);
			for (int i = 0; i < EVENT_COUNT; ++i)
			{
				scanf("%d", &score[i]);
			}

			addPlayer(s1, score);
			break;

		case REMOVEPLAYER:
			scanf("%s", s1);

			removePlayer(s1);
			break;

		case GETRANK:
			scanf("%s %d", s1, &x1);

			ret = getRank(s1, x1);

			scanf("%d", &ans);
			//printf("ans! %d %d\n ", ans,ret);
			if (ret != ans)
			{
				Ans = 0;
			}
			break;

		case COUNTPLAYERS:
			scanf("%d %d %d", &x1, &x2, &x3);

			ret = countPlayers(x1, x2, x3);

			scanf("%d", &ans);
			//printf("ans! %d %d\n ", ans, ret);
			if (ret != ans)
			{
				Ans = 0;
			}
			break;
		}
	}

	return Ans;
}

int main()
{
	//setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);

	int T, Ans;
	scanf("%d %d", &T, &Ans);

	for (int tc = 1; tc <= T; tc++)
	{
		printf("#%d %d\n", tc, run(Ans));
	}

	return 0;
}