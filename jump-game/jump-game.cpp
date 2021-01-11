class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        vector<bool> index(nums.size());
        index[nums.size()-1] = true;
        int indexToReach = nums.size()-1;
        for(int i = nums.size()-2; i>=0; i--) {
            if(nums[i]+i>=indexToReach) {
                index[i] = true;
                indexToReach = i;
            }
            else
                index[i] = false;
        }
        return index[0];
        
    }
};
