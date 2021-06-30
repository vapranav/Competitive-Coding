vector<string> res;
class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.length() == 0)
            return vector<string>();
        unordered_map<char, string> Map;
        Map['2'] = "abc";
        Map['3'] = "def";
        Map['4'] = "ghi";
        Map['5'] = "jkl";
        Map['6'] = "mno";
        Map['7'] = "pqrs";
        Map['8'] = "tuv";
        Map['9'] = "wxyz";
        string temp = "";
        
        backtrack(0, digits, temp, Map);
        return res;
    }
    
    void backtrack(int index, string &input, string &word, unordered_map<char,string> &umap) {
        if(index == input.length()) {
            res.push_back(word);
            return;
        }
        
        string values = umap[input[index]];
        for(auto value: values) {
            word+=value;
            backtrack(index+1, input, word, umap);
            word = word.erase(word.length()-1, 1);
        }
    }
};