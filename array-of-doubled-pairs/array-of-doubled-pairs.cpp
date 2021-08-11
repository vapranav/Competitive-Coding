class Solution {
public:
    
    static bool cmp(int a, int b) {
        return abs(a) < abs(b);
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> umap;
        for(auto i: arr) {
            if(umap.find(i) == umap.end()) 
                umap[i] = 1;
            else
                umap[i]++;
        }
        vector<int> b = arr;
        sort(b.begin(), b.end(), cmp);
        
        for(auto i: umap) {
            cout<<i.first<<" "<<i.second<<endl;
        }
        
        //return true;
        
        for(auto i: b) {
            if(umap[i] == 0) continue;
            if(umap[2*i] <= 0)
                return false;
            umap[2*i]--;
            umap[i]--;
        }
        return true;
        
    }
};