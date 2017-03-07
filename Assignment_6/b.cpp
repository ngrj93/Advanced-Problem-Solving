#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) { 
		map <int, long long > mp;
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < q; i++) {
			int source, dest, c;
			cin >> source >> dest >> c;
			mp[source] -= c;
			mp[dest] += c;
		}
		priority_queue<long long > min_heap;
		priority_queue<long long > max_heap;
		for (map<int, long long >::iterator it = mp.begin (); it != mp.end (); it++) {
			if (it->second < 0)
				min_heap.push (-it->second);
			else if (it->second > 0)
				max_heap.push (it->second);
		}
		int count = 0;
		while (true) {
			long long min_element = 0, max_element = 0;
			if (! min_heap.empty ()) 
				min_element = min_heap.top ();
			if (! max_heap.empty ())
				max_element = max_heap.top ();
			if (max_element == 0 && min_element == 0)
				break;
			int abs_min = min (min_element, max_element);
			min_element -= abs_min;
			max_element -= abs_min;
			min_heap.pop ();
			max_heap.pop ();
			if (min_element == 0) {
				if (max_element != 0)
					max_heap.push (max_element);
			}
			else {
				if (min_element != 0)
					min_heap.push (min_element);
			}
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
			



