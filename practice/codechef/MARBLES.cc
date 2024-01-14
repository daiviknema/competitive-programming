/**
 * Difficuty: Medium
 * Status: AC
 * Time: 55 mins 4 sec
 */
#include <iostream>
#include <vector>

typedef long long int ll;

using namespace std;


ll c (ll n, ll r) {
	if (r > n)  return 0;
	ll rnew = (r > n-r) ? (n-r) : r;

	if (rnew == 0) return 1;
	if (rnew == 1) return n;

	ll ans = 1;
	for (ll i = 1; i <= rnew; i++) {
		ans *= (n-rnew+i);
		ans /= i;
	}
	return ans;
}

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		cout << c(n-1, k-1) << endl;
	}
	return 0;
}
