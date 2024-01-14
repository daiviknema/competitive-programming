/**
 * Difficulty: Beginner
 * Status: AC
 * Time: 2 min 34 sec
 */
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c == 180) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

