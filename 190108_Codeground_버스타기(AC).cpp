//190118 약 3시간 소요 시간초과로 27점 획득 시간복잡도 감소가 관권
//3시간 소요 이유는 vector의 숙련도 부족  
//vector <int> candid(num_person) 이라 했더니 벡터에 값이 안들어감 

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int Answer;

int main(){
	int T, test_case;
	
	cin>>T;
	for(test_case=0;test_case<T;test_case++)
	{
	
		Answer=0;
		int num_person,gap;
		
		cin>>num_person>>gap;
		vector <int> candid;
		vector <vector <int> > ads;
		
		int tmp;
		for(int i=0;i<num_person;i++){
			
			cin>>tmp;
			candid.push_back(tmp);
		}
		
		for(int i=0;i<num_person;i++)
		{
		
			int sk,flag=0;
			//cout<< candid[i];
			sk=candid[i];	
			if(ads.size()==0)
			{
				vector <int> ad;
				ad.push_back(sk);
				ads.push_back(ad);
			}
			else
			{
				for(int k=0; k<ads.size();k++)
				{
					for(int l=0;l<ads[k].size();l++)
					{
						
						if(abs(ads[k][l]-sk)<=gap)
						{
						break;
						}
					
						if(l==(ads[k].size()-1))
						{
						
						flag=1; ads[k].push_back(sk); break;
						}
						
					}
				
					if(flag==1)break;
					else if(k==(ads.size()-1)&&flag==0)
					{
						vector <int> ad;
						ad.push_back(sk);
						ads.push_back(ad);
						break;
					}		
				}
			}	
		}
		Answer=ads.size();
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
	
	return 0;
}
