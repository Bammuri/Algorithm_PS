//1340 ����
//1435 �ϼ� �� ������ set ���� std ���� ��������
//set�� ������ �̸� ���ı��� ����
//1450 iterator����

//1500 ���� ���� ���� 
//1510 �ذ� but set�� �ȵ� �׳� ��� ���� ++ �ι��� ;;
//1515 ���� �� ���� 50 ���� 8�� ����
//1530 -10 ȭ��� set �ʱ�ȭ ����
//1�ð� 40��
//<set> 
//��� ��� �����̳� ���� ����Ʈ���� ����
//key�� �Ҹ��� ���ҵ��� �������� �̷���� �����̳� key �ߺ������ �ȵ�
//�ߺ��Ϸ��� multiset
//�ߺ��� �ȵ� ������ s.insert, �ʱ�ȭ�� ���ı�������
//map<int>::iterator=�̸�.begin() /(*it) 
//������ find�� ���ٰ��� ã���� �ش� �ּ� �ƴϸ� �̸�.end()��ȯ 
#include <cstdio>
#include <set>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;
#define FOR(i,n)for(int i=0;i<n;i++)
int n, k, chop, tmp, test_case;
int nums[28];

set <int,greater<int> > s;


void more(int i){

	FOR(j, chop){

		for (i; i < n; i++, j++){
			tmp += nums[i] << (chop-j-1)*4;
		}
		int k = chop - j ;
		FOR(a, k){
			tmp += nums[a] << (chop - j-1) * 4;
			j++;
		}

	}

}


void solve(){
	chop = n / 4;
	FOR(i, n){
		tmp = 0;
		if (i + chop > n){
			more(i);
		}
		else{
			for (int t = i; t < i + chop; t++){
				tmp += nums[t] << (chop-1-(t-i))*4;
			}
		}
		
		//printf("%x ", tmp);
		s.insert(tmp);
	}
	//printf("\n");

	set<int>::iterator it=s.begin();
	k -= 1;
	while (k--){ it++; }
	printf("#%d %d\n", test_case, (*it));
}

int main(int argc, char** argv)
{

	int T;
	scanf("%d", &T);


	for (test_case = 1; test_case <= T; ++test_case)
	{
		s.clear();
		memset(nums, 0, sizeof(nums));
		scanf("%d%d", &n, &k);
		FOR(i, n) scanf("%1x", &nums[i]);
		//FOR(i, n)printf("%d ", nums[i]);
		solve();

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}