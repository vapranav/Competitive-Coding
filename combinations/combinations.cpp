class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res, n, k, 1, temp);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, int n, int k, int s, vector<int> temp) {
        if(temp.size() == k) {
            res.push_back(temp);
            return;
        }
        
        for(int i = s; i<=n; i++) {
            temp.push_back(i);
            dfs(res, n, k, i+1, temp);
            temp.pop_back();
        }
        
        return;
    }
};