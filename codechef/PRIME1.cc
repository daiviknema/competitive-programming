/**
 * Difficulty: Easy
 * Status: AC
 * Time: 32 min 51 sec
 */
#include <iostream>
#include <vector>

typedef long long int ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> primes;
	vector<bool> prime(100000, true);
	prime[1] = false;
	for (int i = 2; i<prime.size(); i++) {
		if (prime[i]) {
			for (int k = 2; k*i < prime.size(); k++) prime[k*i] = false;
			primes.push_back(i);
		}
	}
// 	for (int i = 0; i< 10; i++) cout << primes[i] << endl;
	while (t--) {
		int l, h;
		cin >> l >> h;
		vector<bool> primesInRange(h-l+1, true);
		for (int j = 0; j < primes.size(); j++) {
			for (int k = (l/primes[j]); k*primes[j] <= h; k++) {
				if (k != 1 && k*primes[j] >= l) primesInRange[k*primes[j] - l] = false;
			}
		}
		if (l == 1) primesInRange[0] = false;
		for (int i = 0; i < primesInRange.size(); i++) {
			if (primesInRange[i]) cout << l+i << endl;
		}
	}
	return 0;
}
