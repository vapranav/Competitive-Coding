class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        int j = k-1;
        int minimum = INT_MAX;
        int start, end;
        while(j<arr.size()) {
            int tot = 0;
            for(int a = i; a<=j; a++) {
                int diff = abs(arr[a] - x);
                tot+=diff;
            }
            if(tot<minimum) {
                minimum = tot;
                start = i;
                end = j;
            }
            i++;
            j++;
        }
        return vector<int>(arr.begin() + start, arr.begin() + end + 1);
    }
};