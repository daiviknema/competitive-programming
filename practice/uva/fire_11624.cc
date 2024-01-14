#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;

const ll inf = 1000000000+9;

int main(int argc, char ** argv) {
	ll t;
	cin >> t;
	while(t--) {
		ll r, c;
		cin >> r >> c;
		vvi grid(r, vi(c, 0));
		string tmp;
		// 0 means empty
		// 1 means wall
		// 2 means fire
		ii jack_init = ii(-1,-1);
		queue<ii> fire_coords;
		vvi fire_lvl(r, vi(c,inf));
		vvi fire_vis(r, vi(c,0));
		for(ll i=0; i<r; i++) {
			cin >> tmp;
			for(ll j=0; j<c; j++) {
				if(tmp[j] == '#') {
					grid[i][j] = 1;
				} else if(tmp[j] == 'F') {
					grid[i][j] = 2;
					fire_coords.push(ii(i,j));
					fire_lvl[i][j] = 0;
					fire_vis[i][j] = 1;
				} else if(tmp[j] == 'J') {
					jack_init = ii(i,j);
				} else {
					// pass
				}
			}
		}
		// Perform BFS for fire
		while(!fire_coords.empty()) {
			ii cur = fire_coords.front();
			fire_coords.pop();
			ll r_cur = cur.first;
			ll c_cur = cur.second;
			fire_vis[r_cur][c_cur] = 2;
			if(r_cur+1 < r && fire_vis[r_cur+1][c_cur] == 0 && grid[r_cur+1][c_cur] != 1) {
				fire_coords.push(ii(r_cur+1,c_cur));
				fire_vis[r_cur+1][c_cur] = 1;
				fire_lvl[r_cur+1][c_cur] = fire_lvl[r_cur][c_cur]+1;
			}
			if(r_cur-1 >= 0 && fire_vis[r_cur-1][c_cur] == 0 && grid[r_cur-1][c_cur] != 1) {
				fire_coords.push(ii(r_cur-1,c_cur));
				fire_vis[r_cur-1][c_cur] = 1;
				fire_lvl[r_cur-1][c_cur] = fire_lvl[r_cur][c_cur]+1;
			}
			if(c_cur+1 < c && fire_vis[r_cur][c_cur+1] == 0 && grid[r_cur][c_cur+1] != 1) {
				fire_coords.push(ii(r_cur,c_cur+1));
				fire_vis[r_cur][c_cur+1] = 1;
				fire_lvl[r_cur][c_cur+1] = fire_lvl[r_cur][c_cur]+1;
			}
			if(c_cur-1 >= 0 && fire_vis[r_cur][c_cur-1] == 0 && grid[r_cur][c_cur-1] != 1) {
				fire_coords.push(ii(r_cur,c_cur-1));
				fire_vis[r_cur][c_cur-1] = 1;
				fire_lvl[r_cur][c_cur-1] = fire_lvl[r_cur][c_cur]+1;
			}
		}
		/*
		cout << "Fire BFS" << endl;
		for(ll i=0; i<r; i++) {
			for(ll j=0; j<c; j++) {
				cout << fire_lvl[i][j] << "\t";
			}
			cout << endl;
		}
		*/
		// Perform BFS for Jack
		queue<ii> jack_coords;
		vvi jack_lvl(r, vi(c,inf));
		vvi jack_vis(r, vi(c,0));
		jack_vis[jack_init.first][jack_init.second] = 1;
		jack_lvl[jack_init.first][jack_init.second] = 0;
		jack_coords.push(jack_init);
		while(!jack_coords.empty()) {
			ii cur = jack_coords.front();
			jack_coords.pop();
			ll r_cur = cur.first;
			ll c_cur = cur.second;
			jack_vis[r_cur][c_cur] = 2;
			if(r_cur+1 < r && jack_vis[r_cur+1][c_cur] == 0 && grid[r_cur+1][c_cur] != 1 && jack_lvl[r_cur][c_cur]+1 < fire_lvl[r_cur+1][c_cur]) {
				jack_coords.push(ii(r_cur+1,c_cur));
				jack_vis[r_cur+1][c_cur] = 1;
				jack_lvl[r_cur+1][c_cur] = jack_lvl[r_cur][c_cur]+1;
			}
			if(r_cur-1 >= 0 && jack_vis[r_cur-1][c_cur] == 0 && grid[r_cur-1][c_cur] != 1 && jack_lvl[r_cur][c_cur]+1 < fire_lvl[r_cur-1][c_cur]) {
				jack_coords.push(ii(r_cur-1,c_cur));
				jack_vis[r_cur-1][c_cur] = 1;
				jack_lvl[r_cur-1][c_cur] = jack_lvl[r_cur][c_cur]+1;
			}
			if(c_cur+1 < c && jack_vis[r_cur][c_cur+1] == 0 && grid[r_cur][c_cur+1] != 1 && jack_lvl[r_cur][c_cur]+1 < fire_lvl[r_cur][c_cur+1]) {
				jack_coords.push(ii(r_cur,c_cur+1));
				jack_vis[r_cur][c_cur+1] = 1;
				jack_lvl[r_cur][c_cur+1] = jack_lvl[r_cur][c_cur]+1;
			}
			if(c_cur-1 >= 0 && jack_vis[r_cur][c_cur-1] == 0 && grid[r_cur][c_cur-1] != 1 && jack_lvl[r_cur][c_cur]+1 < fire_lvl[r_cur][c_cur-1]) {
				jack_coords.push(ii(r_cur,c_cur-1));
				jack_vis[r_cur][c_cur-1] = 1;
				jack_lvl[r_cur][c_cur-1] = jack_lvl[r_cur][c_cur]+1;
			}
		}
		/*
		cout << "Jack BFS" << endl;
		for(ll i=0; i<r; i++) {
			for(ll j=0; j<c; j++) {
				cout << jack_lvl[i][j] << "\t";
			}
			cout << endl;
		}
		*/
		ll min_time = inf;
		for(ll i=0; i<c; i++) {
			if(jack_lvl[0][i] < min_time) min_time = jack_lvl[0][i];
			if(jack_lvl[r-1][i] < min_time) min_time = jack_lvl[r-1][i];
		}
		for(ll i=1; i<r-1; i++) {
			if(jack_lvl[i][0] < min_time) min_time = jack_lvl[i][0];
			if(jack_lvl[i][c-1] < min_time) min_time = jack_lvl[i][c-1];
		}
		if(min_time == inf) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << min_time+1 << endl;
		}

	}
	return 0;
}
