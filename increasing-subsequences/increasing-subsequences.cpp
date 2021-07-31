class Solution {
public:
    void generate(int index, set<vector<int>>& res, vector<int>& tmp, vector<int>& nums) {
        if(tmp.size() >= 2) {
            res.insert(tmp);
        } 
        
        for(int i = index; i<nums.size(); i++) {
            if(tmp.size() == 0 || nums[i] >= tmp.back()) {
                tmp.push_back(nums[i]);
                generate(i+1, res, tmp, nums);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        res.clear();
        vector<int> tmp;
        generate(0,res, tmp, nums);
        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }
};