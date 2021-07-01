class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //two pointer approach with outer for loop 
        if(nums.size()<3)
            return vector<vector<int>>();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2; i++) {
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) 
                continue;
            int j = i+1;
            int k = nums.size()-1;
            
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    cout<<"true";
                    res.push_back(triplet);
                    //removing duplicates

                    while(j<nums.size()-1 && nums[j] == nums[j+1]) 
                        j++;
                    while(k>i && nums[k] == nums[k-1])
                        k--;

                    j++;
                    k--;
                }
                else if(sum<0)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};