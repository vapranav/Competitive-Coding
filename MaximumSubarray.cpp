/*
Question
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Approach
- Brute force (O(n^3) -> O(n^2))
- Kadane's Algorithm (O(n))
*/

//Solution

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int result = nums[0];
        dp[0] = nums[0];
        if(nums.size()==1)
            return nums[0];
        for(int i= 1; i<nums.size(); i++)  {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            if(dp[i]>=result)
                result = dp[i];
        }
        return result; 
    }
};
