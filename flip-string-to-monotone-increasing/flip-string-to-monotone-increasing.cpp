class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> res(s.length()+1);
        res[0] = 0;
        int oneCounter = 0;
        for(int i = 0; i<s.length(); i++) {
            if(s[i] == '1') {
                res[i+1] = res[i];
                oneCounter++;
            }
            else {
                res[i+1] = min(res[i]+1, oneCounter);
            }
        }
        return res[s.length()];
    }
};