//1340 시작
//1435 완성 ㄴ 컴파일 set 문제 std 선언 순서문제
//set은 넣을때 미리 정렬구현 가능
//1450 iterator문제

//1500 삽입 순서 오류 
//1510 해결 but set에 안들어감 그냥 출력 삽질 ++ 두번함 ;;
//1515 테케 다 맞음 50 개중 8개 맞춤
//1530 -10 화장실 set 초기화 문제
//1시간 40분
//<set> 
//노드 기반 컨데이녀 균형 이진트리로 구현
//key라 불리는 원소들의 집합으로 이루어진 컨테이너 key 중복허용이 안됨
//중복하려면 multiset
//중복이 안됨 삽입은 s.insert, 초기화시 정렬구현가능
//map<int>::iterator=이름.begin() /(*it) 
//접근은 find로 접근가능 찾으면 해당 주소 아니면 이름.end()반환 
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}