class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        generate(res, candidates, target, temp, 0);
        return res;
    }
    
    void generate(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& temp, int start) {
        int sum = 0;
        for(auto i: temp) 
            sum+=i;
        
        if(sum>target)
            return;
        
        if(sum == target) {
            res.push_back(temp);
            return;
        }
            
        
        for(int i = start; i<candidates.size(); i++) {
            temp.push_back(candidates[i]);
            generate(res, candidates, target, temp, i);
            temp.pop_back();
        }
    }
};