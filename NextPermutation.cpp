/*
Question
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Approach
- Go from right, check where smaller number exists before a bigger number (this is the point of swap). After swapping we need to sort the remaining elements to the right of point of swap in ascending order.  

Key Points
In place replacement and constant memory suggests swapping

*/


//Solution 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while (i>=0 && nums[i] >= nums[i+1]) {
            i--;
        }
        if(i>=0) {
            int j = nums.size()-1;
            while(j>=0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums,i+1);
    }
    
    void reverse(vector<int>& nums, int beg) {
        int i = beg;
        int j = nums.size() - 1;
        while(i < j) {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};
