#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max(int a, int b) {
	return (a>b)? a:b;
}

int LCS(char arr1[], char arr2[], int m, int n) {
	if(arr1[m] == '\0' || arr2[n] == '\0') {
		return 0;
	} 
	if(arr1[m-1] == arr2[n-1]) {
		return 1 + LCS(arr1, arr2, m+1, n+1);
	}
	else 
	return max(LCS(arr1, arr2, m+1, n), LCS(arr1, arr2, m, n+1));
}

int main() {
	char a[] = "PRANAV";
	char b[] = "RAV";
	
	int sizea = strlen(a);
	int sizeb = strlen(b);
	
	cout<<LCS(a,b,0,0);
}
