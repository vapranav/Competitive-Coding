class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int s = nums.size();
        int res;
        int maximum = nums[0];
        int minimum = nums[s-1];
        
        vector<int> maxPrefix(s);
        vector<int> minSuffix(s);
        
        for(int i = 0; i<s; i++) {
            if(nums[i] >= maximum)
                maximum = nums[i];
            maxPrefix[i] = maximum;
        }
        
        for(int i = s-1; i>=0; i--) {
            if(nums[i] <= minimum)
                minimum = nums[i];
            minSuffix[i] = minimum;
        }
        
        // if max youve seen till now is less than the min ahead return the index
        
        for(int i = 1; i<s; i++) {
            if(maxPrefix[i-1] <= minSuffix[i]) {
                res = i;
                break;   
            }
        }
        
        /* for(auto i: maxPrefix)
            cout<<i<<" ";
        for(auto i: minSuffix)
            cout<<i<<" ";
        */
        return res;
    }
};
