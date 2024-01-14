#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000+9;

int main(int argc, char ** argv) {

	ll v;
	cin >> v;
	vvi al(v);
	for(ll i=0; i<v; i++) {
		ll n;
		cin >> n;
		for(ll j=0; j<n; j++) {
			ll tmp;
			cin >> tmp;
			al[i].push_back(tmp);
		}
	}
	ll t;
	cin >> t;
	while(t--) {
		ll src;
		cin >> src;
		queue<ll> q;
		q.push(src);
		vi cnt(v+1,0);
		vi lvl(v,inf);
		lvl[src] = 0;
		vector<bool> vis(v, false);
		while(!q.empty()) {
			ll cur = q.front();
			q.pop();
			vis[cur] = true;
			for(ll i=0; i<al[cur].size(); i++) {
				if(!vis[al[cur][i]]) {
					lvl[al[cur][i]] = min(lvl[al[cur][i]], lvl[cur]+1);
					q.push(al[cur][i]);
				}
			}
		}
		/*
		for(ll i=0; i<v; i++) {
			cout << lvl[i] << " ";
		}
		cout << endl;
		*/
		for(ll i=0; i<v; i++) {
			if(lvl[i] != inf) cnt[lvl[i]] += 1;
		}
		ll max_cnt = -inf;
		ll arg_max = inf;
		for(ll i=1; i<v+1; i++) {
			if(cnt[i] > max_cnt) {
				max_cnt = cnt[i];
				arg_max = i;
			}
		}
		if(al[src].empty()) {
			cout << 0 << endl;
		} else {
			cout << max_cnt << " " << arg_max << endl;
		}
		/*
		if(max_cnt > 1)
			cout << max_cnt << " " << arg_max << endl;
		else
			cout << 0 << endl;
		*/
	}
	return 0;
}
