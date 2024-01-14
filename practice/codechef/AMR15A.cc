/**
 * Difficulty: Beginner
 * Status: AC
 * Time: 3 min 38 sec
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, w;
	cin >> n;
	int lucky = 0;
	for (int i = 0; i<n; i++) {
		cin >> w;
		if (w%2 ==0) lucky ++;
	}
	string s = (lucky > (n - lucky)) ? "READY FOR BATTLE" : "NOT READY";
	cout << s << endl;
	return 0;
}
