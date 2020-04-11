#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max(int a, int b) {
	return (a>b)? a: b;
}
int main() {
	char a[] = "AGGTAB";
	char b[] = "GXTXAYB";
	
	int sizea = strlen(a);
	int sizeb = strlen(b);
	
	int dp[sizea+1][sizeb+1];
	
	for(int i = 0; i<sizea; i++) {
		dp[i][0] = 0;
	}
	
	for(int j = 0; j<sizeb; j++) {
		dp[0][j] = 0;
	}
	
	for(int i = 1; i<=sizea; i++) {
		for(int j = 1; j<=sizeb; j++) {
			if(a[i] == b[j]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else 
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	cout<<dp[sizea][sizeb];
}
