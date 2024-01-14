#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef map<ll, set<ll> > al_t;
typedef set<ll>::iterator setiter_t;

const ll inf = 1000000000+9;

int main(int argc, char ** argv) {
	ios_base::sync_with_stdio(false);
	ll case_num = 1;
	while(true) {
		ll e;
		cin >> e;
		al_t al;
		if(e == 0) break;
		set<ll> vertices;
		for(ll i=0; i<e; i++) {
			ll a, b;
			cin >> a >> b;
			al[a].insert(b);
			al[b].insert(a);
			vertices.insert(a);
			vertices.insert(b);
		}
		for(ll i=0;; i++) {
			ll src, ttl;
			cin >> src >> ttl;
			if(src == 0 && ttl == 0) break;
			map<ll, ll> lvl;
			for(setiter_t setiter = vertices.begin();
					setiter != vertices.end();
					setiter ++) {
				lvl[*setiter] = inf;
			}
			queue<ll> q;
			q.push(src);
			lvl[src] = 0;
			map<ll, bool> vis;
			while(!q.empty()) {
				ll curr = q.front();
				q.pop();
				vis[curr] = true;
				for(setiter_t setiter = al[curr].begin();
						setiter != al[curr].end();
						setiter++) {
					if(!vis[*setiter]) {
						lvl[*setiter] = min(lvl[*setiter], lvl[curr]+1);
						q.push(*setiter);
					}
				}
			}
			/*
			for(setiter_t setiter = vertices.begin();
					setiter != vertices.end();
					setiter++) {
				cout << (*setiter) << " " << lvl[*setiter] << endl;
			}
			cout << "=========" << endl;
			*/
			ll cnt = 0;
			for(setiter_t setiter = vertices.begin();
					setiter != vertices.end();
					setiter++) {
				if(lvl[*setiter] > ttl) {
					//cout << *setiter << " " << lvl[*setiter] << endl;
					cnt++;
				}
			}
			cout << "Case " << case_num++ << ": " << cnt << " nodes not reachable from node " << src << " with TTL = " << ttl << "." << endl;
		}


	}
	return 0;
}
