class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);
        
        for(int i = 0; i<s1.length(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        
        for(int i = 0; i<s2.length() - s1.length(); i++) {
            if(permutation(s1map, s2map))
                return true;
            else {
                s2map[s2[i+s1.length()] - 'a']++;
                s2map[s2[i] - 'a']--;
            }
        }
        
        return permutation(s1map, s2map);
    }
    
    bool permutation(vector<int> s1, vector<int> s2) {
        for(int i = 0; i<26; i++) {
            if(s1[i] != s2[i])
                return false;
        }
        return true;
    }
};