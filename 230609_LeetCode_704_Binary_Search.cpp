class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int pivot, left = 0, right = nums.size()-1;

    while (left <= right){
        pivot = (left + right)/2;
        if(nums[pivot] == target) return pivot;
        if(nums[pivot] > target) right = pivot -1;
        else left = pivot + 1;
    }
    return -1;
  }
};