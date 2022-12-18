#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

vector<vector<int>>memo;

int dp(vector<vector<char>>&grid, int n, int i, int j) {
	if(i >= n || j>=n || grid[i][j] == '*')
		return 0;

	if(i == n-1 && j == n-1)
		return 1;

	if(memo[i][j] != -1)
		return memo[i][j] % MOD;

	int ans = 0;
	int right = dp(grid, n, i+1, j);
	int down = dp(grid, n, i, j+1);

	ans += ( (right) % MOD + (down) % MOD ) % MOD;

	return memo[i][j] = ans % MOD;
}

int main() {
	int n;
	cin>>n;

	vector<vector<char>>grid(n, vector<char>(n, '#'));

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			char ch;
			cin>>ch;
			grid[i][j] = ch;
		}
	}
   
	memo.resize(n+1, vector<int>(n+1, -1));

	int ans = dp(grid, n, 0, 0);
	cout<<ans<<"\n";
}