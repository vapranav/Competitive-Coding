#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include<string>
#include<vector>
using namespace std;

bool editInsert(string s1, string s2) {
    string smaller = s1.length() < s2.length() ? s1: s2;
    string bigger = s1.length() < s2.length() ? s2: s1;
    int index1 = 0;
    int index2 = 0;
    while(index1 < s1.length() && index2 < s2.length()) {
        if(smaller[index1] != bigger[index2]) {
            if(smaller[index1] != bigger[index2+1])
                return false;
            else {
                index1++;
                index2+=2;
            }
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool equalLength(string s1, string s2) {
    bool foundDifference = false;
    int index1 = 0;
    int index2 = 0;
    while(index1 < s1.length() && index2 < s2.length()) {
        if(s1[index1] != s2[index2]) {
            if(foundDifference) 
                return false;
            foundDifference = true;
        } 
        index1++;
        index2++;
    }
    return true;
}

bool oneEdit(string s1, string s2) {
    int lenDiff = s1.length() - s2.length();
    if(abs(lenDiff) > 1)
        return false;
    if(lenDiff == 0)
        return equalLength(s1, s2);
    else
        return editInsert(s1, s2);
}

bool refactoredOneEdit(string s1, string s2) {
    int lenDiff = s1.length() - s2.length();
    if(abs(lenDiff) > 1)
        return false;
    bool foundDifference = false;
    string smaller = s1.length() < s2.length() ? s1: s2;
    string bigger = s1.length() < s2.length() ? s2: s1;
    int index1 = 0;
    int index2 = 0;
    while(index1 < s1.length() && index2 < s2.length()) {
        if(smaller[index1] != bigger[index2]) {
            if(foundDifference) 
                return false;
            foundDifference = true;
            if(lenDiff != 0) {
                if(smaller[index1] != bigger[index2+1])
                    return false;
                else {
                    index1++;
                    index2+=2;
                }
            } else {
                index1++;
                index2++;
            }
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool newOneEdit(string s1, string s2) {
    int lenDiff = s1.length() - s2.length();
    if(abs(lenDiff) > 1)
        return false;
    bool foundDifference = false;
    string smaller = s1.length() < s2.length() ? s1: s2;
    string bigger = s1.length() < s2.length() ? s2: s1;
    int index1 = 0;
    int index2 = 0;
    while(index1 < s1.length() && index2 < s2.length()) {
        if(s1[index1] != s2[index2]) {
            if(foundDifference) 
                return false;
            foundDifference = true;
            if(lenDiff == 0) 
                index1++;
        } else {
            index1++;
        }
        index2++;
    }
    return true;
}

int main()
{
    vector<string> inputs1 = {"pales", "pale", "pale", "adxy", "mdxy", "maxy", "mady", "madx", "aexy"};
    vector<string> inputs2 = {"pale", "bale", "bake", "madxy", "madxy", "madxy", "madxy", "madxy", "madxy"};
    for(int i = 0; i<9; i++) {
        bool res = newOneEdit(inputs1[i], inputs2[i]);
        cout<<res<<endl;
    }
}
/*
1
1
0
1
1
1
1
1
0
*/



