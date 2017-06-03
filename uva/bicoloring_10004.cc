#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main(int argc, char ** argv) {
	while(true) {
		ll n;
		cin >> n;
		if(n==0) break;
		vvi al(n);
		ll e;
		cin >> e;
		for(ll i=0; i<e; i++) {
			ll a,b;
			cin >> a >> b;
			al[a].push_back(b);
			al[b].push_back(a);
		}
		queue<ll> q;
		vector<bool> vis(n,false);
		vi col(n,-1);
		q.push(0);
		col[0] = 0;
		bool bicolor = true;
		while(!q.empty()) {
			ll cur = q.front();
			q.pop();
			vis[cur] = true;
			for(ll i=0; i<al[cur].size(); i++) {
				if(!vis[al[cur][i]] && col[al[cur][i]] != col[cur]) {
					q.push(al[cur][i]);
					col[al[cur][i]] = 1ll^col[cur];
				} else if(!vis[al[cur][i]] && col[al[cur][i]] == col[cur]) {
					bicolor = false;
				}
			}
		}
		if(bicolor) {
			cout << "BICOLORABLE." << endl;
		} else {
			cout << "NOT BICOLORABLE." << endl;
		}

	}
	return 0;
}
