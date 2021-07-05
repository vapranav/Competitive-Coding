class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return func(start, arr, visited);
    }
    
    bool func(int start,vector<int> &arr, vector<bool> &v) {
        if(start<0 || start>arr.size()-1 || v[start])
            return false;
        if(arr[start] == 0)
            return true;
        v[start] = true;
        int newPlusStart = start + arr[start];
        int newMinusStart = start - arr[start];
        return func(newPlusStart, arr, v) || func(newMinusStart, arr, v);
    }
};
