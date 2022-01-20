class Solution {
public:
    
    void dfs(vector<vector<char>> &grid, int x, int y, int rows, int cols) {
        if(x<0 || x>=rows || y<0 || y >=cols || grid[x][y] != '1')
            return;
        grid[x][y] = '2';
        dfs(grid, x+1, y, rows, cols);
        dfs(grid, x-1, y, rows, cols);
        dfs(grid, x, y+1, rows, cols);
        dfs(grid, x, y-1, rows, cols);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int num_islands = 0;
        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, rows, cols);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }
};