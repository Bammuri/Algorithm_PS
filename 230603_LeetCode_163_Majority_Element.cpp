#include <unordered_map>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        int majorityElement = -1;
        int majorityElement_size = 0;
    
        for (int ele : nums) {
            um[ele]++;
            if ( majorityElement_size < um[ele]) {
                majorityElement = ele;
                majorityElement_size = um[ele];
            }
        }
        return majorityElement;   
    }
};