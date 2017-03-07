#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int witch[n+1];
		for (int i = 1; i <= n; i++)
			cin >> witch[i];
		witch[0] = 0;
		sort (witch, witch + n + 1);
		long long experience = 0, sum = 0;
		for (int i = n; i >= 0; i--) {
			experience = max (experience, i * sum + sum);
			sum = sum + witch[i];
		}
		cout << experience << endl;
	}
	return 0;
}


