class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefixProduct(size);
        prefixProduct[0] = 1;
        vector<int> suffixProduct(size);
        suffixProduct[size-1] = 1;
        vector<int> res;
        int pre = 1, suf = 1;
        for(int i = 1; i<size; i++) {
            pre*=nums[i-1];
            prefixProduct[i] = pre;
        }
        for(int i = size-2; i>=0; i--) {
            suf*=nums[i+1];
            suffixProduct[i] = suf;
        }
        
        for(int i = 0; i<size; i++) {
            res.push_back(prefixProduct[i] * suffixProduct[i]);
        }
        return res;
    }
};