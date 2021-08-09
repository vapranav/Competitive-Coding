class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++) {
            for(int j = 0; j<board[0].size(); j++) {
                if(dfs(board, i, j, word))
                    return true;
            }
        }
       return false;
    }
    
    bool dfs(vector<vector<char>> &board, int x, int y, string& s) {
        if(s.length() == 0)
            return true;
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] != s[0])
            return false;
        char c = board[x][y];
        board[x][y] = '*';
        string st = s.substr(1);
        bool res = dfs(board, x+1, y, st) || dfs(board, x-1, y, st) || dfs(board, x, y+1, st) || dfs(board, x, y-1, st);
        board[x][y] = c;
        return res;
    }
};