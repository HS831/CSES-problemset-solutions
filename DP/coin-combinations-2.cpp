#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
// vector<vector<int>>memo;

// int dp(vector<int>&coins, int n, int sum, int i) {
// 	if(sum == 0)
// 		return 1;

// 	if(i >= n)
// 		return 0;

// 	if(memo[i][sum] != -1)
// 		return memo[i][sum] % MOD;

// 	int ans = 0;
// 	if(coins[i] <= sum) {
// 		ans = ( ( dp(coins, n, sum - coins[i], i) % MOD ) + ( dp(coins, n, sum, i+1) % MOD ) ) % MOD;
// 	}
// 	else {
// 		ans = ( dp(coins, n, sum, i+1) % MOD );
// 	}

// 	return memo[i][sum] = ans % MOD;
// }

int twoD_dp(vector<int>&coins, int n, int sum) {
	int dp[n+1][sum+1];
	dp[0][0] = 1;

	for(int i=0; i<=n; i++) dp[i][0] = 1;
	for(int j=1; j<=sum; j++) dp[0][j] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) {
			if(coins[i-1] <= j) {
				dp[i][j] = ( ( dp[i][j - coins[i-1]] % MOD ) + ( dp[i-1][j] % MOD ) );
			}
			else {
				dp[i][j] = ( dp[i-1][j] % MOD );
			}
		}
	}

	for(int i=0; i<n+1; i++) {
		for(int j=0; j<sum+1; j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<endl;
	return dp[n][sum] % MOD;

}

int main() {
	int n,x;
	cin>>n>>x;

	vector<int>coins(n);
	for(int i=0; i<n; i++) 
		cin>>coins[i];

//	memo.resize(n, vector<int>(x+1, -1));

	int ans = twoD_dp(coins, n, x);

	cout<<ans<<"\n";
}