#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(int argc, char ** argv) {
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll s1 = ((n)*(n+1ll))/2ll;
		ll i = 0ll;
		ll pow2 = 1ll;
		ll s2 = 0ll;
		while((pow2<<i) <= n) {
			s2 += (pow2<<i);
			i++;
		}
		cout << s1-2ll*s2 << endl;
	}
	return 0;

}
