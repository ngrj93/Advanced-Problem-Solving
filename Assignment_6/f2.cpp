#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<pair<int,int > > dimension;

int stack_papers () {
	vector<int> dp;
	for (int i = 0; i < n; i++) {
		vector<int>::iterator it = upper_bound (dp.begin (), dp.end (), dimension[i].second);
		if (it == dp.end ())
			dp.push_back (dimension[i].second);
		else
			*it = dimension[i].second;

		for (int i = 0;i < dp.size(); i++)
			cout <<dp[i]<<" ";
		cout << endl;
	}
	return dp.size ();
}

/*int stack_papers () {
	bool visited[n];
	memset (visited, 0, sizeof (visited));
	int ans = 0;
	for (int q = 0; q < n; q++) {
		if (! visited[q]) {
			visited[q] = true;
			int cur_best = 1, cur = q;
			for (int i = q + 1; i < n; i++) {
				if ( dimension[cur].first > dimension[i].first && 
							dimension[cur].second > dimension[i].second) {
					cur_best += 1;
					cur = i;
					visited[cur] = true; 
				}
			}
			ans = max (cur_best, ans);
		}
	}
	return ans;
}*/
			
int main () {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int l, w;
			cin >> l >> w;
			dimension.push_back (make_pair (l,w));
		}
		sort (dimension.rbegin (), dimension.rend ());
		//for (int i =0;i<dimension.size();i++)
		//	cout << dimension[i].first << " " <<dimension[i].second << endl;
		cout << stack_papers () << endl;	
	}
	return 0;
}
