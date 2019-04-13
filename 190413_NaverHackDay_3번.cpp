// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &T) {
    // write your code in C++14 (g++ 6.2.0)
    int st=T[0],ans=0;
    for(int i=T.size()-1;i>=0;i--)
        if(T[i]<=st){ans=i+1;break;}
    
    
    return ans;
}
