/**
 * Difficulty: Beginner
 * Status: AC
 * Time: 7 min 4 sec
 */
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int n100 = n/100;
		n = n%100;
		int n50 = n/50;
		n = n%50;
		int n10 = n/10;
		n = n%10;

		int n5 = n/5;
		n = n%5;

		int n2 = n/2;
		n=n%2;

		int n1 = n/1;

		cout << (n100 + n50 + n10 + n5 + n2+ n1) << endl;
	}
	return 0;
}
