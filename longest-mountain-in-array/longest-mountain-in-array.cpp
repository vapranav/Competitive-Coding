class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)
            return 0;
        int maxLen = 0;
        int low, high;
        int i = 1;
        while(i<=arr.size()-2) {
            low = i;
            high = i;
            int ctr = 0;
            if(arr[low-1] < arr[i] and arr[high+1] < arr[i]) {
                while(low-1>=0 and arr[low-1] < arr[low]) {
                    ctr++;
                    low--;
                }
                while(high+1<arr.size() and arr[high+1]<arr[high]) {
                    ctr++;
                    high++;
                }
                
                if(ctr+1>maxLen)
                    maxLen = ctr+1;
                
                i++;
                
            } else {
                i++;
            }
        }
        return maxLen;
    }
};