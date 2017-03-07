#include <bits/stdc++.h>
#define MAXSIZE 5015
using namespace std;

int matrix[MAXSIZE][MAXSIZE][2];

int main () {
	string first_line, second_line;
	cin >> first_line >> second_line;

	int count = 0;
	int m = (int) first_line.size ();
	int n = (int) second_line.size ();

	for (int i = 1, k = m; k >= 1; i++, k--) {
		for (int j = 1, l = n; l >= 1; j++, l--) {
			if (first_line[i-1] == second_line[j-1]) 
				matrix[i][j][0] = matrix[i-1][j-1][0] + 1;
			else if (matrix[i-1][j][0] >= matrix[i][j-1][0]) 
				matrix[i][j][0] = matrix[i-1][j][0];
			else 
				matrix[i][j][0] = matrix[i][j-1][0];

			if (first_line[k-1] == second_line[l-1]) 
				matrix[k][l][1] = matrix[k+1][l+1][1] + 1;
			else if (matrix[k+1][l][1] >= matrix[k][l+1][1]) 
				matrix[k][l][1] = matrix[k+1][l][1];
			else 
				matrix[k][l][1] = matrix[k][l+1][1];
		}
	}
	
	int longest_seq = matrix[m][n][0];

	for (int i = 0; i <= m; i++) {
		set<char> s;
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j-1][0] + matrix[i+1][j+1][1] == longest_seq) 
				s.insert (second_line[j-1]);
		}
		count += s.size();
	}
	
	cout << count << endl;
	return 0;
}
