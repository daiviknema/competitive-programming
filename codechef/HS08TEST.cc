/**
 * Difficulty: Beginner
 * Status: AC
 * Time: 6 min 55 s
 */
#include <iostream>

using namespace std;

int main() {
	int toWithdraw = 0; double balance = 0.0;
	cin >> toWithdraw >> balance;

	if ((double)toWithdraw + (double)0.5 > balance || toWithdraw % 5 != 0) {
		cout << balance << endl;
	} else {
		cout << (balance - (double)toWithdraw - 0.5) << endl;
	}
	return 0;
}
