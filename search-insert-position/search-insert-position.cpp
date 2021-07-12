class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = l + (r-l)/2;
        
        while(l<=r) {
            if(target > nums[mid]) {
                l = mid + 1;
                mid = l + (r-l)/2;
            }
            else if(target < nums[mid]) {
                r = mid - 1;
                mid = l + (r-l)/2;
            }
                
            else
                return mid;
        }
        return mid;
    }
};