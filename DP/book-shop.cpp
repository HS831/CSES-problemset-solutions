#include<bits/stdc++.h>
using namespace std;
	
// vector<vector<int>>memo;

// int dp(vector<int>&prices, vector<int>&pages, int n, int capacity, int i) {
// 	if(i == n)
// 		return 0;

// 	if(memo[i][capacity] != -1)
// 		return memo[i][capacity];

// 	int ans = -1;
// 	if(capacity >= prices[i]) {
// 		ans = max(dp(prices, pages, n, capacity - prices[i], i+1) + pages[i], 
// 				  dp(prices, pages, n, capacity, i+1));
// 	}
// 	else {
// 		ans = dp(prices, pages, n, capacity, i+1);
// 	}

// 	return memo[i][capacity] = ans;

// }

int tabulation(vector<int>&prices, vector<int>&pages, int n, int capacity) {
	int dp[n+1][capacity+1];

	for(int i=0; i<=capacity; i++) dp[0][i] = 0;
	for(int j=0; j<=n; j++) dp[j][0] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=capacity; j++) {
			if(prices[i-1] <= j) {
				dp[i][j] = max(dp[i-1][j - prices[i-1]] + pages[i-1], dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][capacity];

}

int main() {
	int n,capacity;
	cin>>n>>capacity;	// x = capacity

	vector<int>price(n);
	for(int i=0; i<n; i++)
		cin>>price[i];    // price for each book

	vector<int>pages(n);
	for(int i=0; i<n; i++)
		cin>>pages[i];    // number of pages for each book

//	 memo.resize(n+1, vector<int>(capacity+1, -1));

	// int ans = dp(price, pages, n, capacity, 0);

	int ans = tabulation(price, pages, n, capacity);
	cout<<ans<<"\n";	
}