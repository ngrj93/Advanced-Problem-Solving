#include <bits/stdc++.h>
#define MAXSIZE 10001
using namespace std;

int t, n;
int dp[MAXSIZE];

class Node {
	public:
		int first;
		int second;
};

bool my_comparator (Node n1, Node n2) {
	return n1.first * n1.second > n2.first * n2.second;
}

int memo_calculate (int current, Node arr[]) {
	if (dp[current] != -1) 
		return dp[current];
	else {
		int best = 0;
		for (int i = current + 1; i < n; i++) {
			if (arr[i].first < arr[current].first && arr[i].second < arr[current].second) 
				best = max (best, memo_calculate (i, arr));
		}
		return (dp[current] = best + 1);
	}
}	
				
int main () {
	cin >> t;
	while (t--) { 
		cin >> n;
		Node arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
			dp[i] = -1;
		}
		sort (arr, arr+n, my_comparator); 
		int best = 0;
		for (int i = 0; i < n; i++)
			best = max(best, memo_calculate (i, arr));
		cout << best << endl;
	}
	return 0;
}
