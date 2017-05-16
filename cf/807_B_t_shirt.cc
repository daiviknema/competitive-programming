#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(int argc, char ** argv) {

	vector< set <int> > poss(475);
	for(ll i=0; i<475; i++) {
		ll curr = i;
		for(ll j=0; j<25; j++) {
			curr = (curr * 96 + 42) % 475;
			poss[i].insert(26+curr);
		}
	}
	ll p, x, y;
	cin >> p >> x >> y;
	for(ll i=0; (x-50ll*i)>=y; i++) {
		if(poss[(x-50ll*i)/50ll].find(p) != poss[(x-50ll*i)/50ll].end()) {
			cout << "0" << endl;
			return 0;
		}
	}
	for(ll i=0;; i++) {
		if(poss[(x+50ll*i)/50ll].find(p) != poss[(x+50ll*i)/50ll].end()) {
			cout << ceil((double)(50ll*i)/100.0) << endl;
			return 0;
		}

	}

	return 0;
}
