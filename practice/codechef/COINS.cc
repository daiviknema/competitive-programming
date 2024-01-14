/**
 * Difficulty: Medium
 * Status: AC
 * Time: 24 min 53 sec
 */
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

typedef long long int ll;

map<ll, ll> prec;

ll bcg(ll n) {
	if (n<=4) return n;

	if (prec[n] != 0) return prec[n];
	prec[n] = max(n, bcg(n/2) + bcg(n/3) + bcg(n/4));

	return prec[n];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	while (scanf("%lld", &n) > 0) {
		printf("%lld\n", bcg(n));
	}
	return 0;
}
