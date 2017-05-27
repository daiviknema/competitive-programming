#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef set<ll>::iterator set_iter_t;

vector<ll> toposort;
vector< set<ll> > scc;

void compute_toposort_util(ll src, vvi & al, vector<bool> & vis) {
	vis[src] = true;
	if(!al[src].empty()) {
		for(ll i=0; i<al[src].size(); i++) {
			if(!vis[al[src][i]]) {
				compute_toposort_util(al[src][i], al, vis);
			}
		}
	}
	toposort.push_back(src);
}

void compute_toposort(vvi & al) {
	ll V = al.size();
	vector<bool> vis(V,false);
	for(ll i=0; i<V; i++) {
		if(!vis[i]) {
			compute_toposort_util(i, al, vis);
		}
	}
}

void compute_scc_util(ll src, vvi & al, vector<bool> & vis, set<ll> & cur_scc) {
	cur_scc.insert(src);
	vis[src] = true;
	if(!al[src].empty()) {
		for(ll i=0; i<al[src].size(); i++) {
			if(!vis[al[src][i]]) {
				compute_scc_util(al[src][i], al, vis, cur_scc);
			}
		}
	}
}

void compute_scc(vvi & al) {
	ll V = al.size();
	vector<bool> vis(V, false);
	//for(ll i=0; i<toposort.size(); i++) {
	for(ll i=toposort.size()-1; i>=0; i--) {
		set<ll> cur_scc;
		compute_scc_util(toposort[i], al, vis, cur_scc);
		scc.push_back(cur_scc);
	}
}

bool is_reachable(ll src, ll dest, vvi & al) {
	if(src == dest) return true;
	queue<ll> q;
	q.push(src);
	vector<bool> vis(al.size(), false);
	while(!q.empty()) {
		ll cur = q.front();
		vis[cur] = true;
		q.pop();
		for(ll i=0; i<al[cur].size(); i++) {
			if(al[cur][i] == dest)  return true;
			if(!vis[al[cur][i]]) {
				q.push(al[cur][i]);
			}
		}
	}
	return false;
}

int main(int argc, char ** argv) {
	while(true) {
		ll n;
		cin >> n;
		if(n==0) {
			break;
		}
		ll num;
		string stm;
		vvi al(2*n);
		vvi al_t(2*n);
		for(ll i=0; i<n; i++) {
			cin >> num >> stm;
			if(stm == "true") {
				al[i].push_back(num-1);
				al[num-1+n].push_back(i+n);
				al[i+n].push_back(num-1+n);
				al[num-1].push_back(i);
			} else {
				al[i].push_back(num-1+n);
				al[num-1].push_back(i+n);
				al[i+n].push_back(num-1);
				al[num-1+n].push_back(i);
			}
		}
		bool paradox = false;
		for(ll i=0; i<n; i++) {
			if(is_reachable(i,i+n,al) || is_reachable(i+n,i,al)) {
				paradox = true;
			}
		}
		if(!paradox) cout << "NOT PARADOX" << endl;
		else cout << "PARADOX" << endl;
		/*
		cout << "al" << endl;
		for(ll i=0; i<2*n; i++) {
			cout << i << ": ";
			for(ll j=0; j<al[i].size(); j++) {
				cout << al[i][j] << " ";
			}
			cout << endl;
		}
		compute_toposort(al);
		cout << "Toposort: ";
		for(ll i=0; i<toposort.size(); i++) {
			cout << toposort[i] << " ";
		}
		cout << endl;
		for(ll i=0; i<2*n; i++) {
			for(ll j=0; j<al[i].size(); j++) {
				al_t[al[i][j]].push_back(i);
			}
		}
		cout << "al_t" << endl;
		for(ll i=0; i<2*n; i++) {
			cout << i << ": ";
			for(ll j=0; j<al_t[i].size(); j++) {
				cout << al_t[i][j] << " ";
			}
			cout << endl;
		}
		compute_scc(al_t);
		bool paradox = false;
		for(ll i=0; i<scc.size(); i++) {
			for(set_iter_t set_iter = scc[i].begin();
					set_iter != scc[i].end();
					set_iter++) {
				cout << *set_iter << " ";
				if(scc[i].find((*set_iter)+n) != scc[i].end()) {
					paradox = true;
				}
			}
			cout <<  endl;
		}
		if(paradox)
			cout << "PARADOX" << endl;
		else
			cout << "NOT PARADOX" << endl;
		toposort.clear();
		scc.clear();
		*/
	}
}
