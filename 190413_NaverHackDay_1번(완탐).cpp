// you can use includes, for example:

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int tmp,ans=1987654321;
    int target[6][6]={{0,1,1,1,1,2},
                      {1,0,1,1,2,1},
                      {1,1,0,2,1,1},           
                      {1,1,2,0,1,1},
                      {1,2,1,1,0,1},
                      {2,1,1,1,1,0}};
    for(int i=0;i<6;i++){
        tmp=0;
        for(int j=0;j<A.size();j++){
            tmp+=target[i][A[j]-1];
            
        }
        if(ans>tmp)ans=tmp;
    }
    return ans;
}
