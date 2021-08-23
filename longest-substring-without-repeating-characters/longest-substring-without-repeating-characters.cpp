class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        unordered_map<char, int> umap;
        int i = 0, j = 0, len = INT_MIN;
        while(j<s.length()) {
            if(umap.find(s[j]) == umap.end()) {
                umap[s[j]] = j;
            } else {
                while(i <= umap[s[j]]) {
                    umap.erase(s[i]);
                    i++;
                }
                //i++;
                umap[s[j]] = j;
            }
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};