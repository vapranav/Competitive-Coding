class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s2Len = s2.length();
        int s1Len = s1.length(); 
        if(s2Len<s1Len)
            return false;
        //int index;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(int i = 0; i<s1Len; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        for(int i = 0; i<s2Len-s1Len; i++) {
            if(matches(freq1, freq2)) {
                return true;
            }
            freq2[s2[i] - 'a']--;
            freq2[s2[i+s1Len] - 'a']++;
        }
        
        return matches(freq1, freq2);
    }
        
        bool matches(vector<int> freq1, vector<int> freq2) {
            for(int i = 0; i<26; i++) {
                if(freq1[i] != freq2[i])
                    return false;
            }
            return true;
        }
};