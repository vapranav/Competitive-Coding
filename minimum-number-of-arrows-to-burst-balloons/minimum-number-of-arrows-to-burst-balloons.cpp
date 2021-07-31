class Solution {
    
public:
    
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0]<b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> res;
        sort(points.begin(), points.end(), cmp);
        
        bool flag;
        res.push_back(points[0]);
        
        for(int i = 1; i<points.size(); i++) {
            flag = false;
            for(int j =  0; j<res.size(); j++) {
                if((points[i][0] >= res[j][0]) && (points[i][0] <= res[j][1])) {
                    res[j][0] = max(points[i][0], res[j][0]);
                    res[j][1] = min(points[i][1], res[j][1]);
                    //cout<<interval[0]<<" "<<interval[1]<<endl;
                    flag = true;
                    break;
                } 
            }
            if(!flag) 
                res.push_back(points[i]);
        }
        
        return res.size();
    }
};