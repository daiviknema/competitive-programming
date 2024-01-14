/**
 * Difficulty: Easy
 * Status: AC
 * Time: 7 min 46 sec
 */
#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	vector<ll> c(n, 0);
	for (ll i =0; i < n; i++) cin >> c[i];
	sort(c.begin(), c.end());
	int cnt = 0;
	for (ll i = 0; i < c.size() - 1;) {
		if (c[i+1] - c[i] <= d) {
			cnt++;
			i += 2;
		} else {
			i ++;
		}
	}
	cout << cnt << endl;
}
