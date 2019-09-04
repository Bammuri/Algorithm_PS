#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer,n;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int T, test_case;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int max=0;
		Answer = 0;
	   
	    cin>>n;
	    vector <int> scores(n,0);
	    for(int i=0;i<n;i++) cin>>scores[i];
       
	    sort(scores.begin(),scores.end());
	    
	    for(int i=0;i<n;i++){
            int tmep=scores[i]+n-i;
            if(max<tmep)max=tmep;
	    }
	    
	    for(int i=0;i<n;i++){
	        if(scores[i]+n>=max)Answer++;
	    }


		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
