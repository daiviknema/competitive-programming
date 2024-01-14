#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

const ll inf = 1000000000+9;

int main(int argc, char ** argv) {
	ll t;
	cin >> t;
	while(t--) {
		ll m, n;
		cin >> m >> n;
		vector<string> grid(m);
		vvi al(m, vi(n,0));
		ii src = ii(-1ll,-1ll);
		ii dest = ii(-1ll,-1ll);
		vii horsies;
		for(ll i=0; i<m; i++) {
			cin >> grid[i];
			for(ll j=0; j<n; j++) {
				if(grid[i][j] == 'A') {
					src = ii(i,j);
				} else if(grid[i][j] == 'B') {
					dest = ii(i,j);
				} else if(grid[i][j] == 'Z') {
					horsies.push_back(ii(i,j));
					al[i][j] = 1;
				} else {
					// pass
				}
			}
		}
		for(ll i=0; i<horsies.size(); i++) {
			ll r = horsies[i].first;
			ll c = horsies[i].second;
			if(r-1 >= 0 && c-2 >= 0)
				al[r-1][c-2] = 1;
			if(r+1 < m && c-2 >= 0)
				al[r+1][c-2] = 1;
			if(r-1 >= 0 && c+2 < n)
				al[r-1][c+2] = 1;
			if(r+1 < m && c+2 < n)
				al[r+1][c+2] = 1;

			if(r-2 >= 0 && c-1 >= 0)
				al[r-2][c-1] = 1;
			if(r+2 < m && c-1 >= 0)
				al[r+2][c-1] = 1;
			if(r-2 >= 0 && c+1 < n)
				al[r-2][c+1] = 1;
			if(r+2 < m && c+1 < n)
				al[r+2][c+1] = 1;

		}
		vvi col(m, vi(n,0));
		queue<ii> q;
		vvi lvl(m, vi(n,inf));
		q.push(src);
		lvl[src.first][src.second] = 0;
		col[src.first][src.second] = 1;
		while(!q.empty()) {
			ii cur = q.front();
			q.pop();
			ll r = cur.first;
			ll c = cur.second;
			col[r][c] = 2;
			if(r-1 >= 0 && c-1 >= 0 && col[r-1][c-1] == 0) {
				if(ii(r-1,c-1) == dest){
					q.push(ii(r-1,c-1));
					lvl[r-1][c-1] = lvl[r][c]+1;
					col[r-1][c-1] = 1;
				}
				else if(ii(r-1,c-1) != dest && al[r-1][c-1] == 0) {
					q.push(ii(r-1,c-1));
					lvl[r-1][c-1] = lvl[r][c]+1;
					col[r-1][c-1] = 1;
				}
			}
			if(r+1 < m && c-1 >= 0 && col[r+1][c-1] == 0) {
				if(ii(r+1,c-1) == dest){
					q.push(ii(r+1,c-1));
					lvl[r+1][c-1] = lvl[r][c]+1;
					col[r+1][c-1] = 1;
				}
				else if(ii(r+1,c-1) != dest && al[r+1][c-1] == 0) {
					q.push(ii(r+1,c-1));
					lvl[r+1][c-1] = lvl[r][c]+1;
					col[r+1][c-1] = 1;
				}
			}
			if(r-1 >= 0 && c+1 < n && col[r-1][c+1] == 0) {
				if(ii(r-1,c+1) == dest){
					q.push(ii(r-1,c+1));
					lvl[r-1][c+1] = lvl[r][c]+1;
					col[r-1][c+1] = 1;
				}
				else if(ii(r-1,c+1) != dest && al[r-1][c+1] == 0) {
					q.push(ii(r-1,c+1));
					lvl[r-1][c+1] = lvl[r][c]+1;
					col[r-1][c+1] = 1;
				}
			}
			if(r+1 < m && c+1 < n && col[r+1][c+1] == 0) {
				if(ii(r+1,c+1) == dest){
					q.push(ii(r+1,c+1));
					lvl[r+1][c+1] = lvl[r][c]+1;
					col[r+1][c+1] = 1;
				}
				else if(ii(r+1,c+1) != dest && al[r+1][c+1] == 0) {
					q.push(ii(r+1,c+1));
					lvl[r+1][c+1] = lvl[r][c]+1;
					col[r+1][c+1] = 1;
				}
			}
			if(r >= 0 && c-1 >= 0 && col[r][c-1] == 0) {
				if(ii(r,c-1) == dest){
					q.push(ii(r,c-1));
					lvl[r][c-1] = lvl[r][c]+1;
					col[r][c-1] = 1;
				}
				else if(ii(r,c-1) != dest && al[r][c-1] == 0) {
					q.push(ii(r,c-1));
					lvl[r][c-1] = lvl[r][c]+1;
					col[r][c-1] = 1;
				}
			}
			if(r >= 0 && c+1 < n && col[r][c+1] == 0) {
				if(ii(r,c+1) == dest){
					q.push(ii(r,c+1));
					lvl[r][c+1] = lvl[r][c]+1;
					col[r][c+1] = 1;
				}
				else if(ii(r,c+1) != dest && al[r][c+1] == 0) {
					q.push(ii(r,c+1));
					lvl[r][c+1] = lvl[r][c]+1;
					col[r][c+1] = 1;
				}
			}
			if(r+1 < m && c < n && col[r+1][c] == 0) {
				if(ii(r+1,c) == dest){
					q.push(ii(r+1,c));
					lvl[r+1][c] = lvl[r][c]+1;
					col[r+1][c] = 1;
				}
				else if(ii(r+1,c) != dest && al[r+1][c] == 0) {
					q.push(ii(r+1,c));
					lvl[r+1][c] = lvl[r][c]+1;
					col[r+1][c] = 1;
				}
			}
			if(r-1 >= 0 && c < n && col[r-1][c] == 0) {
				if(ii(r-1,c) == dest){
					q.push(ii(r-1,c));
					lvl[r-1][c] = lvl[r][c]+1;
					col[r-1][c] = 1;
				}
				else if(ii(r-1,c) != dest && al[r-1][c] == 0) {
					q.push(ii(r-1,c));
					lvl[r-1][c] = lvl[r][c]+1;
					col[r-1][c] = 1;
				}
			}
		}
		if(col[dest.first][dest.second] == 2) {
			cout << "Minimal possible length of a trip is " << lvl[dest.first][dest.second] << endl;
		} else {
			cout << "King Peter, you can't go now!" << endl;
		}

	}
	return 0;
}
