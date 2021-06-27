class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int first_pointer = 0;
        int second_pointer = 0;
        
        //make set
        unordered_set <char> set;
        int maximum = 0;
        while(second_pointer < s.length()) {
            //if second pointer value not in set add it to set, find string length, update max value
            if(set.find(s[second_pointer]) == set.end()) {
                set.insert(s[second_pointer]);
                int length = second_pointer - first_pointer + 1;
                maximum = max(maximum, length);
                second_pointer++;
            }
            else {
                set.erase(s[first_pointer]);
                first_pointer++;
            }
        }
        return maximum;
    }
};