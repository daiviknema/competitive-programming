/**
 * Difficulty: Easy
 * Status: AC
 * Time: 13 m 04 sec
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> bn(n, 0);
		int totalMoney = 0;
		for (int i = 0; i < n; i++) {
			cin >> bn[i];
			totalMoney += bn[i];
		}
		int numSweets = totalMoney / x;
		bool inadequate = false;
		for (int i = 0; i < n; i++) {
			// discarding the ith banknote
			if (((totalMoney - bn[i])/x) == numSweets) {
				inadequate  = true;
				break;
			}
		}
		int ans = inadequate ? -1 : numSweets;
		cout << ans << endl;

	}
	return 0;
}
