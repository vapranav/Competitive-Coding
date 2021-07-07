class Solution {
    private:
    static bool cmp(pair<int,int> &a, pair<int, int> &b) {
        return a.second>b.second;
    }
    
public:
    vector<pair<int, int>> Sort(unordered_map<int, int> u) {
        vector<pair<int, int>> A;
        for(auto it: u) 
            A.push_back(it);
        sort(A.begin(), A.end(), cmp);
        return A;
    }
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> umap;
        vector<pair<int, int>> res;
        int len = arr.size();
        for(auto num: arr) {
            if(umap.find(num)!=umap.end())
                umap[num]++;
            else
                umap[num] = 1;
        }
        
        res = Sort(umap);
        int tot = 0;
        int ctr = 0;
        for (int i = 0; i<res.size(); i++) {
            tot+=res[i].second;
            if(tot>=len/2)
                return i+1;
        }
        return 0;
    }
};