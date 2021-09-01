class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        vector<bool> visited(n);
        for(auto i: nums) {
            //visited[i] = 1;
            int cnt = 0;
            while(!visited[i]) {
                cnt++;
                visited[i] = true;
                i = nums[i];
            }
            res = max(cnt, res);
        }
        return res;
    }
};