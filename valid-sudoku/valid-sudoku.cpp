class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows = checkRows(board);
        bool columns = checkColumns(board);
        bool boxes = checkBoxes(board);
        
        
        
        if(rows && columns && boxes)
            return true;
        else
            return false;
    }
    
    bool checkRows(vector<vector<char>>& board) {
        unordered_set<char> s;
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.')
                    continue;
                if(s.find(board[i][j]) == s.end())
                    s.insert(board[i][j]);
                else
                    return false;
            }
            s.clear();
        }
        return true;
    }
    
    bool checkColumns(vector<vector<char>>& board) {
        unordered_set<char> s;
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[j][i] == '.')
                    continue;
                if(s.find(board[j][i]) == s.end())
                    s.insert(board[j][i]);
                else
                    return false;
            }
            s.clear();
        }
        return true;
    }
    
    bool checkBoxes(vector<vector<char>>& board) {
        unordered_set<char> s;
        for(int i = 0; i<9; i++) {
            int mod = i%3;
            int quotient = i/3;
            for(int k = quotient*3; k<quotient*3+3; k++) {
                for(int j = mod*3; j<mod*3+3; j++) {
                    cout<<k<<" "<<j<<" ";
                    if(board[k][j] == '.')
                        continue;
                    if(s.find(board[k][j]) == s.end())
                        s.insert(board[k][j]);
                    else
                        return false;
                }   
            }
            s.clear();
        }
        return true;
    }
};