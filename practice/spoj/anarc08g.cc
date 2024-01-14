#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000;

int main(int argc, char ** argv) {
	ll test_case = 1;
	while(1) {
		ll n;
		cin >> n;
		if(n==0) {
			break;
		}
		vvi am(n, vi(n,0));
		ll max_init = 0;
		for(ll i=0ll; i<n; i++) {
			for(ll j=0ll; j<n; j++) {
				cin >> am[i][j];
				max_init += am[i][j];
			}
		}
		vi net(n,0);
		ll max = 0;
		for(ll i=0ll; i<n; i++) {
			ll tot_out = 0, tot_in = 0;
			for(ll j=0ll; j<n; j++) {
				tot_out += am[i][j];
			}
			for(ll j=0ll; j<n; j++) {
				tot_in += am[j][i];
			}
			net[i] = tot_in-tot_out;
			// cout << net[i] << endl;
			// if(abs(net[i]) > max) max = abs(net[i]);
			if(net[i] > 0) max += net[i];
		}
		cout << test_case << ". " << max_init << " " << max << endl;
		test_case ++;
	}
	return 0;
}
