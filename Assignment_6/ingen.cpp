#include <bits/stdc++.h>

using namespace std;

int main() {
	cout << 150 << endl;
	srand (time (NULL));
	for (int i = 0; i < 100; i++) {
		cout << 10000 << endl;
		for (int j = 0; j < 10000; j++) 
			cout << rand () % 1000000 + 1 <<" "<< rand () % 1000000 + 1 << endl;
	}
	return 0;
}
