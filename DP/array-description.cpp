#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp(vector<int>&a, int n, int m, int i) {
	if( i == n )
		return 0;

	int ans = 0;

	// To be updated
}

int main() {
	int n,m;
	cin>>n>>m;

	vector<int>a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];

	int ans = dp(a, n, m, 0);
	cout<<ans<<"\n";
}