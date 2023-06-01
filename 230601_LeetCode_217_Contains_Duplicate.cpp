#include <unordered_map>
class Solution {
public:
    std::unordered_map<int,int> hash; 
    bool containsDuplicate(vector<int>& nums) {
        for (auto num : nums) {
            hash[num]++;
            if (hash[num] >= 2)
                return true;
        }
        return false;
    }
};