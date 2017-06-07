#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll cur_time = 0;
const ll inf = 1000000000+9;

vii bridges;

void dfsutil(vvi & al, vector<bool> & vis, ll src, vi & disc, vi & low, vi & par) {
	vis[src] = true;
	disc[src] = cur_time++;
	low[src] = disc[src];
	for(ll i=0; i<al[src].size(); i++) {
		if(!vis[al[src][i]]) {
			par[al[src][i]] = src;
			dfsutil(al, vis, al[src][i], disc, low, par);
			low[src] = min(low[src], low[al[src][i]]);
		} else {
			if(al[src][i] != par[src]) low[src] = min(disc[al[src][i]], low[src]);
		}
	}
	for(ll i=0; i<al[src].size(); i++) {
		if(low[al[src][i]] > disc[src]) {
			if(al[src][i] < src) {
				bridges.push_back(ii(al[src][i], src));
			} else {
				bridges.push_back(ii(src, al[src][i]));
			}
		}
	}
}

void dfs(vvi & al) {
	ll v = al.size();
	vector<bool> vis(v,false);
	vi low(v, inf);
	vi disc(v, 0);
	vi par(v, -1);
	for(ll i=0; i<v; i++) {
		if(!vis[i]) {
			dfsutil(al, vis, i, disc, low, par);
		}
	}
	/*
	cout << "disc" << endl;
	for(ll i=0; i<v; i++) cout << i << ": " << disc[i] << endl;
	cout << endl;

	cout << "low" << endl;
	for(ll i=0; i<v; i++) cout << i << ": " << low[i] << endl;
	cout << endl;
	
	cout << "par" << endl;
	for(ll i=0; i<v; i++) cout << i << ": " << par[i] << endl;
	cout << endl;
	*/
	sort(bridges.begin(), bridges.end());
	cout << bridges.size() << " critical links" << endl;
	for(ll i=0; i<bridges.size(); i++)
		cout << bridges[i].first << " - " << bridges[i].second << endl;
	cout << endl;
	cur_time = 0;
	bridges.clear();
}

ll get_num_adj(string s) {
	ll ans = 0ll;
	for(ll i=1; i<=s.length()-2; i++) {
		ans *= 10;
		ans += s[i]-'0';
	}
	return ans;
}

int main(int argc, char ** argv) {
	while(true) {
		ll v;
		if(cin >> v);
		else break;
		vvi al(v);
		for(ll i=0ll; i<v; i++) {
			ll v_no;
			cin >> v_no;
			string x;
			cin >> x;
			ll num_adj = get_num_adj(x);
			// cout << num_adj << endl;
			for(ll j=0ll; j<num_adj; j++) {
				ll adj_v;
				cin >> adj_v;
				al[v_no].push_back(adj_v);
			}
		}
		/*
		for(ll i=0; i<al.size(); i++) {
			cout << i << ": ";
			for(ll j=0; j<al[i].size(); j++) {
				cout << al[i][j] << " ";
			}
			cout << endl;
		}
		*/
		dfs(al);
	}
	return 0;
}
