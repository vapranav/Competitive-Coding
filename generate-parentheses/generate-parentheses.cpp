class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        res.clear();
        backtrack(res, "",n, 0);
        return res;
    }
    
    void backtrack(vector<string> &res, string temp, int n, int m) {
        if(n == 0 && m == 0) {
            res.push_back(temp);
            return;
        }
        
        if(m>0) 
            backtrack(res, temp+")", n, m-1);
        if(n>0)
            backtrack(res, temp+"(", n-1, m+1);
    }
};