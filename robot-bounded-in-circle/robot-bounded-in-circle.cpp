class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int x = 0; int y = 0; int facing = 0;
        
        for(auto ins: instructions) {
            if(ins == 'L') 
                facing = (facing + 1) % 4;
            else if(ins == 'R')
                facing = (facing + 3) % 4;
            else
                x+= directions[facing][0], y+= directions[facing][1];
        }
        return x == 0 && y == 0 || facing>0;
    }
};



