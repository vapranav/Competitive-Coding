class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         
        if(nums.size() == 1)
            return 0;
        int l = 0;
        int r = nums.size() - 1;
        int maximum = 0;
        int mid = l + (r-l)/2;
        
        while(l<r) {
            mid = l + (r-l)/2;
            if(nums[mid] < nums[mid+1]) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        
        return l;
    }
};