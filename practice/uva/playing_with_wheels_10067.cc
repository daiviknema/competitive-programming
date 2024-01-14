#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000+9;

ll read_state() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	return a*1000ll+b*100ll+c*10ll+d;
}

ll convert(vi & state) {
	ll i=0;
	ll mul=1;
	ll acc = 0;
	while(i < state.size()) {
		acc += state[i]*mul;
		i++;
		mul*=10;
	}
	return acc;
}

ll BFS(const vector<bool> & forbidden, const ll begin, const ll target) {
	// Build adj list
	vvi al(10005);
	for(ll i=0; i<10000; i++) {
		if(!forbidden[i]) {
			ll tmp = i;
			vi state(4,0);
			state[0] = tmp%10ll;
			tmp /= 10ll;
			state[1] = tmp%10ll;
			tmp /= 10ll;
			state[2] = tmp%10ll;
			tmp /= 10ll;
			state[3] = tmp%10ll;
			tmp /= 10ll;
			for(ll j=0; j<4; j++) {
				ll tmp2 = state[j];
				state[j] = (state[j]+1)%10;
				ll candidate = convert(state);
				if(!forbidden[candidate]) {
					al[i].push_back(candidate);
				}
				state[j] = tmp2;
				
				tmp2 = state[j];
				// state[j] = (state[j]-1)%10;
				if(state[j] == 0) state[j] = 9;
				else state[j] = state[j]-1;
				candidate = convert(state);
				if(!forbidden[candidate]) {
					al[i].push_back(candidate);
				}
				state[j] = tmp2;
			}
		}
	}
	/*
	for(ll i=0; i<10000; i++) {
		cout << i << ": ";
		for(ll j=0; j<al[i].size(); j++) {
			cout << al[i][j] << " ";
		}
		cout << endl;
	}
	*/
	// Perform BFS and check if it is possible to get to target
	vector<bool> col(10005, 0);
	vector<ll> lvl(10005, inf);
	queue<ll> q;
	q.push(begin);
	col[begin] = 1;
	lvl[begin] = 0;
	vector<ll> par(10005, inf);
	par[begin] = -1;
	while(!q.empty()) {
		ll cur = q.front();
		q.pop();
		col[cur] = 2;
		// cout << cur << endl;
		// getchar();
		for(ll i=0; i<al[cur].size(); i++) {
			if(col[al[cur][i]] == 0) {
				q.push(al[cur][i]);
				col[al[cur][i]] = 1;
				lvl[al[cur][i]] = lvl[cur]+1;
				par[al[cur][i]] = cur;
			}
		}
	}
	if(col[target] == 0 || lvl[target] == inf) {
		return -1;
	} else {
		/*
		ll cur = target;
		while(cur != -1) {
			cout << cur << endl;
			cur = par[cur];
		}
		*/
		return lvl[target];
	}
}

int main(int argc, char ** argv) {
	ll t;
	cin >> t;
	for(ll test_case = 0; test_case < t; test_case++) {
		ll begin = read_state();
		ll target = read_state();
		// cout << "Begin: " << begin << endl;
		// cout << "Target: " << target << endl;
		// getchar();
		ll num_forb;
		cin >> num_forb;
		// cout << num_forb << endl;
		vector<bool> forb(10005, false);
		for(ll i=0; i<num_forb; i++) {
			ll tmp = read_state();
			// cout << tmp << endl;
			// getchar();
			forb[tmp] = true;
		}
		ll ans = BFS(forb, begin, target);
		cout << ans << endl;
	}
	return 0;
}
