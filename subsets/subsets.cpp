class Solution {
public:
    int k;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        generateSubsets(res, 0, nums, vector<int>());
        return res;
    }
    
    void generateSubsets(vector<vector<int>>& res, int index, vector<int> nums, vector<int> temp) {
        res.push_back(temp);
        if(index>nums.size())
            return;
        for(int i = index; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            generateSubsets(res, i+1, nums, temp);
            temp.pop_back();
        }
    }
};