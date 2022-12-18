#include<bits/stdc++.h>
using namespace std;

// O(N * SUM) when N = SUM ~ O(N^2)

vector<vector<int>>memo;
/*int dp(vector<int>&coins, int sum, int n, int i) {
	if(sum == 0)
		return 0;

	if( i >= n )
		return 	INT_MAX - 1;

	if(memo[i][sum] != -1)
		return memo[i][sum];

	int ans = INT_MAX;
	if(coins[i] <= sum) {
		ans = min(dp(coins, sum - coins[i], n, i) + 1, dp(coins, sum, n, i+1));
	}
	else {
		ans = dp(coins, sum, n, i+1);
	}

	return memo[i][sum] = ans;
}*/

// 2-D tabulation approach ( S.C. O(N * SUM) )

int twoD_DP(vector<int>&coins, int n, int sum) {
	int dp[n+1][sum+1];
	dp[0][0] = 0;

	for(int i=1; i<=sum; i++) dp[0][i] = INT_MAX - 1;
	for(int i=1; i<=n; i++) dp[i][0] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=0; j<=sum; j++) {
			if(coins[i-1] <= j) {
				dp[i][j] = min(dp[i][j - coins[i-1]] + 1, dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][sum] == INT_MAX - 1 ? - 1 : dp[n][sum];
}

// 1-D Tabulation approach ( S.C. O(SUM) )
int oneD_DP(vector<int>&coins, int n, int sum) {
	int dp[sum+1];
	dp[0] = 0;

	for(int i=1; i<=sum; i++) dp[i] = INT_MAX - 1;
	

	for(int i=1; i<=n; i++) {
		for(int j=0; j<=sum; j++) {
			if(coins[i-1] <= j) {
				dp[j] = min(dp[j - coins[i-1]] + 1, dp[j]);
			}
		}
	}

	return dp[sum] == INT_MAX - 1 ? - 1 : dp[sum];
}


int main() {
	int n,x;
	cin>>n>>x;

	vector<int>coins(n);
	for(int i=0; i<n; i++)
		cin>>coins[i];

//	memo.resize(n, vector<int>(x+1, -1));

//	int ans = twoD_DP(coins, n, x);
	int ans = oneD_DP(coins, n, x);
//	ans = ans == INT_MAX - 1 ? -1 : ans;
	cout<<ans<<"\n";
}