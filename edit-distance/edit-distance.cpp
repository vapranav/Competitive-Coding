class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n == 0)
            return m;
        if(m == 0)
            return n;
        vector<vector<int>> dp(n+1, vector<int>(m+1 ));
        for(int i = 0; i<n+1; i++)
            dp[i][0] = i;
        for(int j = 0; j<m+1; j++)
            dp[0][j] = j;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(word1[i] == word2[j])
                    dp[i+1][j+1] = dp[i][j];
                else {
                    int insert = dp[i+1][j];
                    int del = dp[i][j+1];
                    int replace = dp[i][j];
                    dp[i+1][j+1] = min(min(insert, del), replace) + 1;
                }
            }
        }
        for(auto i: dp) {
            for(auto j: i)
                cout<<j<< " ";
            cout<<endl;
        }
        return dp[n][m];
    }
};