#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int>dp;

int memoization(vector<int>&coins, int n, int sum) {
	if(sum == 0)
		return 1;

	if(dp[sum] != -1)
		return dp[sum] % MOD;

	int ans = 0;

	for(auto &coin : coins) {
		if(coin <= sum) {
			ans = ( (ans % MOD) + ( memoization(coins, n, sum - coin) % MOD ) % MOD );
		}
	}

	return dp[sum] = ans % MOD;
}

/*int twoD_dp(vector<int>&coins, int n, int sum) {
	int dp[n+1][sum+1];
	dp[0][0] = 1;

	for(int i=0; i<=n; i++) dp[i][0] = 1;
	for(int j=1; j<=sum; j++) dp[0][j] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) {
			if(coins[i-1] <= j) {
				dp[i][j] = ( ( dp[0][j - coins[i-1]] % MOD ) + ( dp[i-1][j] % MOD ) );
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
	return dp[n][sum];

}*/


int main() {
	int n,x;
	cin>>n>>x;

	vector<int>coins(n);
	for(int i=0; i<n; i++)
		cin>>coins[i];

	dp.resize(x+1, -1);
	int ans = memoization(coins, n, x) % MOD;

//	int ans = twoD_dp(coins, n, x) % MOD;

	cout<<ans<<"\n";
}