class Solution {
public:
    int secondHighest(string s) {
        if(s.length() == 0 || s.length() == 1)
            return -1;
        sort(s.begin(), s.end());
        char first = s[0];
        char second = s[0];
        //cout<<s<<endl;
        for(int i = 1; i<s.length(); i++) {
            if(isdigit(s[i])) {
                //cout<<s[i];
                //cout<<s[i] - '0'<<endl;
                //cout<<first - '0'<<endl;
                if((s[i] - '0') > (first - '0')) {
                    second = first;
                    first = s[i];
                }
            }
        }
        //cout<<second;
        if(first == second)
            return -1;
        else
            return second - '0';
    }
};