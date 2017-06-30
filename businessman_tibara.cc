#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll inf = 1000000000+9;

ll solve(ll D, ll H, vi & t, vi & h, int depth) {
	// for(ll i=0; i<depth; i++) cout << "  ";
	// cout << "solve(D=" << D << ", H=" << H << ")" << endl;
	if(D == 0)
		return 0;
	ll ans = inf;
	for(ll i=0; i<5; i++) {
		if(h[i] <= H)
			ans = min(ans, solve(D-1, H-h[i], t, h, depth+1) + t[i]);
	}
	return ans;
}

int main() {
	ll test_cases;
	cin >> test_cases;
	while(test_cases--) {
		ll H, D;
		cin >> H >> D;
		vi t(5,0), h(5,0);
		for(ll i=0; i<5; i++) {
			ll tmp1, tmp2;
			cin >> tmp1 >> tmp2 >> h[i];
			t[i] = 60*tmp1 + tmp2;
		}
		ll ans = solve(D,H,t,h,0);
		if(ans != inf) {
			ll minutes = ans/60;
			ll seconds = ans%60;
			cout << minutes << " " << seconds << endl;
		} else {
			cout << "-1" << endl;
		}
	}
	return 0;
}
