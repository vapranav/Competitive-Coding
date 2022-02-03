class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool colZero = false;
        bool rowZero = false;
        for(int i = 0; i<r; i++) {
            if(matrix[i][0] == 0) {
                rowZero = true;
                break;
            }
        }
        for(int i = 0; i<c; i++) {
            if(matrix[0][i] == 0) {
                colZero = true;
                break;
            }
        }
        for(int i = 1; i<r; i++) {
            for(int j = 1; j<c; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //nullify rows and cols based on first col/row
        for(int i = 1; i<r; i++) {
            for(int j = 1; j<c; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
            }
        }
        if(rowZero) {
            for(int i = 0; i<r; i++) 
                matrix[i][0] = 0;
        }
        if(colZero) {
            for(int i = 0; i<c; i++) 
                matrix[0][i] = 0;
        }
    }
};