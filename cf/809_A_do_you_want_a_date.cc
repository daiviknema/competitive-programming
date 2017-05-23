#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll M = 1000000000 + 7;

ll modexp(ll base, ll exp, ll mod) {
	ll res = 1ll;
	base = base % mod;
	for(ll i=0ll; i<sizeof(ll)*8; i++) {
		if(exp%2ll == 1ll) {
			res = ((res%mod)*(base%mod))%mod;
		}
		base = ((base%mod)*(base%mod))%mod;
		exp = exp>>1ll;
	}
	return res%mod;
}

int main(int argc, char ** argv) {

	// cout << modexp(2,3,8) << endl;
	// cout << modexp(2,4,7) << endl;
	// cout << modexp(2,5,5) << endl;
	// cout << modexp(2,7,3) << endl;
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	vi x(n+1,0);
	vi pre(n+1,0), pre_rev(n+1,0);
	for(ll i=1ll; i<=n; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	for(ll i=1ll; i<=n; i++) {
		if(i == 1ll) pre[i] = x[i];
		else pre[i] = (pre[i-1]+x[i])%M;
		if(i == 1ll) pre_rev[i] = x[n];
		else pre_rev[i] = (pre_rev[i-1]+x[n-i+1])%M;
	}
	ll s = 0ll;
	for(ll i=0ll; i<n; i++) {
		s += (modexp(2ll,i,M)*((pre_rev[i+1]-pre[i+1])%M))%M;
		s %= M;
	}
	if(s >=0 ) cout << s << endl;
	else cout << (M+s) << endl;
	return 0;
}
