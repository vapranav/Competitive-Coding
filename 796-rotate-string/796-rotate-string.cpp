class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i<s.length(); i++) {
            string x = s.substr(0, i);
            string y = s.substr(i, s.length()-i);
            string conca = y+x;
            if(conca == goal)
                return true;
        }
        return false;
    }
};