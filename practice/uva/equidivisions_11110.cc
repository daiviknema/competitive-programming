#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000+9;

ll dfsutil(vvi & grid, ll r, ll c, vector< vector<bool> > & vis) {
	vis[r][c] = true;
	ll n = grid.size();
	ll num = 1;
	if(r+1 < n && grid[r+1][c] == grid[r][c] && !vis[r+1][c]) {
		num += dfsutil(grid, r+1, c, vis);
	}
	if(r-1 >= 0 && grid[r-1][c] == grid[r][c] && !vis[r-1][c]) {
		num += dfsutil(grid, r-1, c, vis);
	}
	if(c+1 < n && grid[r][c+1] == grid[r][c] && !vis[r][c+1]) {
		num += dfsutil(grid, r, c+1, vis);
	}
	if(c-1 >= 0 && grid[r][c-1] == grid[r][c] && !vis[r][c-1]) {
		num += dfsutil(grid, r, c-1, vis);
	}
	return num;
}

bool dfs(vvi & grid) {
	ll n = grid.size();
	bool eq = true;
	vector< vector<bool> > vis(n, vector<bool> (n, false));
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<n; j++) {
			if(!vis[i][j]) {
				ll num = dfsutil(grid, i, j, vis);
				if(num != n) eq = false;
			}
		}
	}
	return eq;
}


ll conv_to_num(char * tok) {
	ll ans = 0ll;
	for(ll i=0; i<strlen(tok); i++) {
		ans *= 10;
		ans += tok[i]-'0';
	}
	return ans;
}

int main(int argc, char ** argv) {
	ios_base::sync_with_stdio(false);
	while(true) {
		ll n;
		cin >> n;
		if(n == 0) break;
		cin.get();
		vvi grid(n, vi(n,0));
		for(ll i=1; i<n; i++) {
			ll a, b;
			string tmp;
			getline(cin, tmp);
			istringstream cinn(tmp);
			char * tok1, *tok2;
			while(cinn >> a) {
				cinn >> b;
				a -- ;
				b -- ;
				grid[a][b] = i;
			}
		}
		if(dfs(grid)) {
			cout << "good" << endl;
		} else {
			cout << "wrong" << endl;
		}
	}
	return 0;
}
