class Solution {
public:
    
    void generate(int index, set<vector<int>>& s, vector<int>& tmp, vector<int>& nums) {
       
        s.insert(tmp);
        
        if(index>nums.size()-1) 
            return;
        
        for(int i = index; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            generate(i+1, s, tmp, nums);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        generate(0, s, tmp, nums);
        cout<<"hello world";
        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
    
    
};