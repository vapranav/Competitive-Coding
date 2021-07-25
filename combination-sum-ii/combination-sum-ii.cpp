class Solution {
public:
    
    void generate(vector<vector<int>>& res, vector<int> tmp, int index, int sum, int target, vector<int>& candidates) {
        if(sum == target) {
            res.push_back(tmp);
            return;
        } 
        
        if(sum>target || index >= candidates.size())
            return;
        
        for(int i = index; i<candidates.size(); i++) {
            if(i>index && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            generate(res, tmp, i+1, sum+candidates[i], target, candidates);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        generate(res, tmp, 0, 0, target, candidates);
        return res;
    }
};