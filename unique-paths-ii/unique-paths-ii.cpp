class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return dfs(obstacleGrid, 0, 0, dp);
    }
    
    int dfs(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>>& dp) {
        
        if(x<0 || y<0 || x>=obstacleGrid.size() || y>= obstacleGrid[0].size() || obstacleGrid[x][y] == 1)  
            return 0;
        if(dp[x][y] != -1)
            return dp[x][y];
        if(x == obstacleGrid.size() - 1 && y == obstacleGrid[0].size()-1) {
            return 1;
        }
        //obstacleGrid[x][y] = '*';
        dp[x][y] = dfs(obstacleGrid, x+1,y, dp) + dfs(obstacleGrid, x, y+1, dp);
        return dp[x][y];
    }
};