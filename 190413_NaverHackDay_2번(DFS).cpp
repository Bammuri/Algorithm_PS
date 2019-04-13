// you can use includes, for example:
#include <algorithm>
#include <map>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
map <int,int> nums;
int ans=0;


void dfs(tree *TT,int depth){

    if((nums.find(TT->x)->second)==1)return;
    
    
    if(TT->l==NULL&&TT->r==NULL&&ans<depth){
        ans=depth;return;
    }
    else if(TT->l==NULL&&TT->r==NULL&&ans>=depth){
        return;
    }
    
    nums.insert(make_pair(TT->x,1));
    
    if(TT->l!=NULL)
    dfs(TT->l,depth+1);
    

    if(TT->r!=NULL)
    dfs(TT->r,depth+1);
    
    nums.erase(TT->x);
    
}

int solution(tree * T) {
    // write your code in C++14 (g++ 6.2.0)

    dfs(T,1);
    
    return ans;
}
