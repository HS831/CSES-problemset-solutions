#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

vector<int>memo;

int dp(int n, int i) {
	if(i > n)
		return 0;

	if(i == n) 
		return 1;

	if(memo[i] != -1)
		return memo[i] % MOD;

	int ans = 0;
	for(int j=1; j<=6; j++) {
		ans = (ans + dp(n, i+j)%MOD) % MOD;
	}

	return memo[i] = (ans % MOD);
}

int main() {
	int n;
	cin>>n;
	int ans = 0;

	memo.resize(n, -1);

	for(int i=1; i<=6; i++) {
		ans = (ans + dp(n, i) % MOD) % MOD;
	}
	cout<<ans<<"\n";
}