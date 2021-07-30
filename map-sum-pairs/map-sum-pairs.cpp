class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> umap;
    MapSum() {
       
    }
    
    void insert(string key, int val) {
        umap[key] = val;
    }
    
    int sum(string prefix) {
        int tot = 0;
        for(auto i: umap) {
            int len = prefix.size();
            if(i.first.length()>=len) {
                if(i.first.substr(0,len) == prefix) {
                    tot+=i.second;
                }
            }
            //cout<<i.first;
        }
        return tot;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */