#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;

const ll inf = 1000000000+9;

ll DFSUtil(ll src_r, ll src_c, vector< string > & al, vector<vector<bool> > & vis) {
	vis[src_r][src_c] = true;
	ll height = -inf;
	ll r = al.size();
	ll c = al[0].length();
	if(src_r != 0 && al[src_r-1][src_c] == '.' && !vis[src_r-1][src_c]) {
		height = max(height, DFSUtil(src_r-1, src_c, al, vis)+1);
	}
	if(src_c != 0 && al[src_r][src_c-1] == '.' && !vis[src_r][src_c-1]) {
		height = max(height, DFSUtil(src_r, src_c-1, al, vis)+1);
	}
	if(src_r != r-1 && al[src_r+1][src_c] == '.' && !vis[src_r+1][src_c]) {
		height = max(height, DFSUtil(src_r+1, src_c, al, vis)+1);
	}
	if(src_c != c-1 && al[src_r][src_c+1] == '.' && !vis[src_r][src_c+1]) {
		height = max(height, DFSUtil(src_r, src_c+1, al, vis)+1);
	}
	if(height == -inf) return 0;
	else return height;
}

int main(int argc, char ** argv) {
	ll t;
	cin >> t;
	while(t--) {
		ll r, c, src_r, src_c;
		cin >> c >> r;
		vector<string> grid(r);
		bool start_found = false;
		for(ll i=0; i<r; i++) {
			cin >> grid[i];
			for(ll j=0; j<c; j++)
				if(!start_found && grid[i][j] == '.') {
					src_r = i;
					src_c = j;
					start_found = true;
				}
		}
		vi heights;
		vector<vector<bool> > vis(r, vector<bool>(c, false));
		vis[src_r][src_c] = true;
		if(src_r != 0 && grid[src_r-1][src_c] == '.' && !vis[src_r-1][src_c]) {
			heights.push_back(DFSUtil(src_r-1, src_c, grid, vis));
		}
		if(src_c != 0 && grid[src_r][src_c-1] == '.' && !vis[src_r][src_c-1]) {
			heights.push_back(DFSUtil(src_r, src_c-1, grid, vis));
		}
		if(src_r != r-1 && grid[src_r+1][src_c] == '.' && !vis[src_r+1][src_c]) {
			heights.push_back(DFSUtil(src_r+1, src_c, grid, vis));
		}
		if(src_c != c-1 && grid[src_r][src_c+1] == '.' && !vis[src_r][src_c+1]) {
			heights.push_back(DFSUtil(src_r, src_c+1, grid, vis));
		}
		sort(heights.begin(), heights.end());
		if(heights.empty()) {
			cout << 0 << endl;
		} else if(heights.size() >= 2) {
			cout << heights[heights.size()-1] + heights[heights.size()-2] +2 << endl;
		} else {
			cout << heights[heights.size()-1]+1 << endl;
		}
	}

	return 0;
}
