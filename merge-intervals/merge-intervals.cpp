class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> interval = intervals[0];
        vector<vector<int>> res;
        for(int i = 1; i<intervals.size(); i++) {
            //for(int j = 0; i<intervals.size(); i++) {
                if(intervals[i][0] >= interval[0] && intervals[i][0] <= interval[1]) {
                    interval[1] = max(interval[1],intervals[i][1]);
                } 
            else {
                res.push_back(interval);
                interval[0] = intervals[i][0];
                interval[1] = intervals[i][1];
            }
            //}
        }
        res.push_back(interval);
        return res;
    }
    
};