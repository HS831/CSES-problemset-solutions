#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;

	vector<int>dp(n+1, INT_MAX);
	dp[0] = 0;

	for(int i=1; i<=n; i++) {
		string num = to_string(i);
		for(char &ch : num) {
			dp[i] = min(dp[i], dp[i - (ch - '0')] + 1);
		} 
	}

	cout<<dp[n]<<"\n";
}