// MIXTURES -- recursive solution
// As expected - TLE
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000+9;

ll solve(vi & a, vi & pre, ll beg, ll end) {
	if(beg == end) {
		return 0;
	} else if(beg+1 == end) {
		return a[beg]*a[end];
	}
	ll ans = inf;
	for(ll i=beg; i<(end); i++) {
		ans = min(ans, solve(a, pre, beg, i) + solve(a, pre, i+1, end) + ((pre[end]-pre[i])%100)*((pre[i] - pre[beg] + a[beg])%100));
	}
	return ans;
}

int main(int argc, char ** argv) {
	ll n;
	while(cin >> n) {
		vi a(n,0);
		vi pre(n,0);
		for(ll i=0; i<n; i++) {
			cin >> a[i];
			if(i == 0) pre[i] = a[i];
			else pre[i] = pre[i-1]+a[i];
		}
		cout << solve(a, pre, 0, n-1) << endl;
	}

	return 0;
}
