class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len-1;
        int mid;
        if(len == 1)
            return nums[0];
        if(nums[l] != nums[l+1])
            return nums[l];
        if(nums[r] != nums[r-1])
            return nums[r];
        while(l<r) {
            mid = l + (r-l)/2;
            if(nums[mid+1] != nums[mid] && nums[mid-1] != nums[mid]) 
                break;
            if(mid%2 != 0) {
                if(nums[mid+1] == nums[mid])
                    r = mid;
                else 
                    l = mid;
            }
            else {
                if(nums[mid+1] == nums[mid]) 
                    l = mid;
                else
                    r = mid;
                }
            }
        return nums[mid];
    }
};