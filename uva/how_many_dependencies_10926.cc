#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000+9;

ll dfsutil(vvi & al, vector<bool> & vis, ll src, vi & deps) {
	ll ret = 1;
	vis[src] = true;
	// cout << "Im at " << src << endl;
	for(ll i=0; i<al[src].size(); i++) {
		if(!vis[al[src][i]]) {
			ret += dfsutil(al, vis, al[src][i], deps);
		}
	}
	return ret;
}

void dfs(vvi & al) {
	ll v = al.size();
	vector<bool> vis(v, false);
	vi deps(v, 0);
	for(ll i=0; i<v; i++) {
		// cout << "dfsutil on " << i << endl;
		deps[i] = dfsutil(al, vis, i, deps) - 1ll;
		// vis.clear();
		fill(vis.begin(), vis.end(), false);
		// for(ll j=0; j<v; j++) vis[j] = false;
	}
	/*
	for(ll i=0; i<v; i++) {
		cout << i << ": " << deps[i] << endl;
	}
	*/
	ll deps_max = -inf;
	ll arg_deps_max = -1;
	for(ll i=0; i<v; i++) {
		if(deps[i] > deps_max) {
			deps_max = deps[i];
			arg_deps_max = i;
		}
	}
	cout << arg_deps_max+1 << endl;
}

int main(int argc, char ** argv) {
	while(true) {
		ll n;
		cin >> n;
		if(n == 0) break;
		vvi al(n);
		for(ll i=0; i<n; i++) {
			ll numd;
			cin >> numd;
			for(ll j=0; j<numd; j++) {
				ll dep;
				cin >> dep;
				dep--;
				al[i].push_back(dep);
			}
		}
		dfs(al);
	}
	return 0;
}
