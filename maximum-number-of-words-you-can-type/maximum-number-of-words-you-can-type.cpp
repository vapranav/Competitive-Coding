class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> s;
        for(auto i: brokenLetters) 
            s.insert(i);
        vector<string> tokens;
        int i = 0, ctr = 0, k = 0;
        int j;
        while(i<text.length()) {
            j = i;
            while(j<text.length()) {
                if(text[j] == ' ' || j == text.length() - 1) {
                    tokens.push_back(text.substr(i, j-i+1));
                    i = j+1;
                    break;
                } else
                    j++;
            }
        }
        while(k<tokens.size()) {
            for(int i = 0; i<tokens[k].length(); i++) {
                if(s.find(tokens[k][i]) != s.end()) 
                    break;
                if(i == tokens[k].length() - 1) 
                    ctr++;
            }
            k++;
        }
        return ctr;
    }
};