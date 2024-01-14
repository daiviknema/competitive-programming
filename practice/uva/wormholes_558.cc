#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000+9;

int main(int argc, char ** argv) {
	ll num_cases;
	cin >> num_cases;
	while(num_cases--) {
		ll v, e;
		cin >> v >> e;
		vvi al(v);
		ll a, b, w;
		for(ll i=0; i<e; i++) {
			cin >> a >> b >> w;
			al[a].push_back(b);
			al[a].push_back(w);
		}
		vi dis(v, inf);
		vi par(v, -1);
		dis[0] = 0;
		for(ll i=0; i<v-1; i++) {
			for(ll j=0; j<v; j++) {
				for(ll k=0; k<al[j].size(); k+=2) {
					if(dis[j] + al[j][k+1] < dis[al[j][k]]) {
						dis[al[j][k]] = dis[j] + al[j][k+1];
						par[al[j][k]] = j;
					}
				}
			}
		}
		bool neg_cycles = false;
		for(ll j=0; j<v; j++) {
			for(ll k=0; k<al[j].size(); k+=2) {
				if(dis[j] + al[j][k+1] < dis[al[j][k]]) {
					neg_cycles = true;
				}
			}
		}
		// for(ll i=0; i<v; i++)
		// 	cout << i << ": " << dis[i] << " " << endl;
		// cout << endl;
		// for(ll i=0; i<v; i++)
		// 	cout << i << ": " << par[i] << " " << endl;
		// cout << endl;
		if(neg_cycles) cout << "possible" << endl;
		else cout << "not possible" << endl;
	}
	return 0;
}
