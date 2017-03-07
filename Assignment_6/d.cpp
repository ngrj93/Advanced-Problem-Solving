#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--) {
		string input, result;
		cin >> input;
		vector <deque<int > > v (26);
		int length = (int)input.size () - 1;
		bool occured[26] = {0};
		for (int i = 0; i <= length; i++) 
			v[input[i] - 'a'].push_back (i);
		for (int i = 0; i <= length; i++) {
			int cur_char = input[i] - 'a';
			if (! occured[cur_char]) {
				v[cur_char].pop_front ();
				if (v[cur_char].empty ()) 
					result += input[i];
				else {
					bool flag = true;
					int bound = INT_MAX;
					for (int j = 0; j < 26; j++) {
						if (! occured[j] && ! v[j].empty ()) 
							bound = min(bound, v[j].back ());
					}
					for (int j = cur_char - 1; j >= 0; j--) {
						if (! v[j].empty () && ! occured[j] && v[j].front () <= bound) {
							flag = false;
							break;
						}
					}
					if (flag == true) {
						result += input[i];
						occured[cur_char] = true;
					}
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}
