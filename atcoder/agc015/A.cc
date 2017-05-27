#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

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
	ll n, a, b;
	cin >> n >> a >> b;
	if(n == 1) {
		if(a!=b) cout << 0 << endl;
		else cout << 1 << endl;
		return 0;
	}
	if(a<b)
		cout << ((n-1)*b+a)-((n-1)*a+b)+1 << endl;
	else if(a == b)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}
