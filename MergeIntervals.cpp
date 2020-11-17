/*Question
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Approach
- Sort according to start time and iterate over intervals. If start time of current interval < end time of previous interval merge the intervals else push_back the current interval. 
- Alternate Method (Interval Trees) 

Key Points
- 2D vector sorting (rowwise/columnwise) using C++ Lambda function.
- comparator function within Solution class has to be static.
- Push the first element into the res and process using res (When loop starts from second element in cases of comparison)
*/

// Solution

class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2) { 
        return v1[0] < v2[0]; 
    }
    void sortVector(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),sortcol);
    } 
        
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //Sort the intervals based on start time
        sortVector(intervals);
        for(int i = 0; i < intervals.size(); i++) {
            cout<<intervals[i][0]<<" "<<intervals[i][1];
            cout<<endl;
        }     
        
        //Merge intervals
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
        if (res.back()[1] < intervals[i][0]) res.push_back(intervals[i]);
        else
            res.back()[1] = max(res.back()[1], intervals[i][1]);
    }
        return res;
    }
};
