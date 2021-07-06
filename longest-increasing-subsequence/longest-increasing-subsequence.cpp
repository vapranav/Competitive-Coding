class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        for(int i = 0; i<nums.size(); i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        
        int longest = INT_MIN;
        for(auto i: dp) {
            if(i > longest) 
                longest = i;
        }
        return longest;
    }
};