#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();
	int dp[m+1][n+1];
	for(int j=0;j<=n;j++) {
		dp[0][j] = 0;
	}
	for(int i=0;i<=m;i++) {
		dp[i][0] = 0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int longestPalindromicSubsequence(string s) {
	string s2="";
	for(int i=s.length()-1;i>=0;i--) {
		s2 += s[i];
	}
	return lcs(s, s2);
}

int main() {
	string s;
	cout<<"Enter the string:"<<endl;
	cin>>s;
	int ans = longestPalindromicSubsequence(s);
	cout<<"Length of Longest Palindromic Subsequence is: "<<ans;
	return 0;
}
