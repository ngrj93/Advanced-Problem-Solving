#include<bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n, x, y;
		cin >> n >> x >> y;
		long long dp[n + 2];
		dp[0] = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (i % 2 == 0) {
				dp[i] = min (dp[i / 2] +y, dp[i-1] + x);
				dp[i-1] = min (dp[i-1], dp[i] + x);
			}
			else
				dp[i] = dp[i-1] + x;
		}
		cout << dp[n] << endl;
	}
	return 0;
}
