class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0) 
            return NULL;
        if(len == 1) 
            return s;
        bool dp[len][len];
        
        int maximum = 0;
        string res;
        
        //dp init (dp[i][j] denotes whether s[i..j] is palindrome or not)
        
        for(int i = len-1; i>=0; i--) {
            for(int j = i; j<len; j++) {
                int leng = j-i+1;
                if(i == j)
                    dp[i][j] = true;
                else if(j == i+1) 
                    dp[i][j] = s[i] == s[j] ? true: false;
                else
                    dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]) ? true: false;
                if(dp[i][j] == true && leng>=maximum) {
                    maximum = leng;
                    res = s.substr(i, leng);
                } 
            }
        }   
            
    return res;
    }
};