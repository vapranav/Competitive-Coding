#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include<string>
#include<vector>
using namespace std;

string stringCompression(string s) {
    int len = s.length();
    int i = 0;
    int j;
    string res = "";
    while(i<len) {
        char current = s[i];
        res+=current;
        j = i+1;
        while(j<=len) {
            if(s[j] == current) {
                j++;
            } else {
                res+=to_string(j-i);
                i = j;
                break;
            }
        }
    }
    return res.length() > s.length() ? s: res;
}

int main()
{
    vector<string> inputs1 = {"pales", "pale", "pale", "adxy", "mdxy", "maxy", "mady", "madx", "aexy", "aabcccccaaa"};
    for(int i = 0; i<10; i++) {
        string res = stringCompression(inputs1[i]);
        cout<<res<<endl;
    }
}



