class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> res;
        for(auto st: strs) {
            string word = st;
            sort(st.begin(), st.end());
            umap[st].push_back(word);
        }
       
       for(auto p: umap) {
            res.push_back(p.second);
        }
        return res;
    }
};