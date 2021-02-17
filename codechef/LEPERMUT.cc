/**
 * Difficulty: Easy
 * Status: AC
 * Time: 12 min
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> per(n, 0);
		for (int i = 0; i<n; i++) cin >> per[i];
		int inv = 0;
		int inv_loc = 0;
		for (int i = 0; i < n; i++) {
			if (i != n-1 && per[i+1] < per[i]) inv_loc ++;
			for (int j = i+1; j < n; j++) {
				if (per[j] < per[i]) inv ++;
			}
		}

		string res = (inv == inv_loc) ? "YES" : "NO";

		cout << res << endl;
	}
}
