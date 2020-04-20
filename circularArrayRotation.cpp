#include <bits/stdc++.h>

using namespace std;

//O(n) Space Complexity

int main()
{
    int size, rotCount, noQueries, queu;
    cin>>size>>rotCount>>noQueries;
    int oldArray[size];
    for(int i = 0; i<size; i++) {
        cin>>oldArray[i];
    }

    int newArray[size];
    int newIndex;

    for(int i = 0; i<size; i++) {
    newIndex = (i+rotCount)%size;
    newArray[newIndex] = oldArray[i];
    }

    while(noQueries) {
        cin>>queu;
        cout<<newArray[queu];
        cout<<"\n";
        noQueries--;
    }
}

//O(1) Space Complexity

#include <bits/stdc++.h>

using namespace std;

// Complete the circularArrayRotation function below.
void findElement(int size, int rotCount, int queu, int oldArray[]) {
    int newIndex;
    for(int i = 0; i<size; i++) {
        newIndex = (i+rotCount)%size;
        if(newIndex == queu) {
            cout<<oldArray[i];
        }
    }
}

int main()
{
    int size, rotCount, noQueries, queu;
    cin>>size>>rotCount>>noQueries;
    int oldArray[size];
    for(int i = 0; i<size; i++) {
        cin>>oldArray[i];
    }

    while(noQueries) {
        cin>>queu;
        findElement(size, rotCount, queu, oldArray);
        cout<<"\n";
        noQueries--;
    }
}

