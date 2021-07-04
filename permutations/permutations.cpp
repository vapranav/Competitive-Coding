vector<vector<int>> res;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        vector<int> partialArray;
        backtrack(nums, partialArray, nums.size());
        return res;
    }
    
    void backtrack(vector<int> &Nums, vector<int> partialArray, int max) {
        if(partialArray.size() == max) {
            res.push_back(partialArray);
            return;
        }
        
        
        for(int i = 0; i<Nums.size(); i++) {
            if (std::count(partialArray.begin(), partialArray.end(), Nums[i])) continue;
            partialArray.push_back(Nums[i]);
            backtrack(Nums, partialArray, max);
            partialArray.pop_back();
        }
    }
};