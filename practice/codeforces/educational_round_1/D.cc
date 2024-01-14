#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;

map <ii, ll> coord_cc;
map <ll, ll> cc_pic;


void DFSUtil(vvi & mu, vvi & cc, vector<vector<bool> > & vis, ll r_src, ll c_src, ll cc_num) {
	ll rows = mu.size();
	ll cols = mu[0].size();
	vis[r_src][c_src] = true;
	cc[r_src][c_src] = cc_num;
	coord_cc[ii(r_src, c_src)] = cc_num;
	ll num_adj = 4;
	if(r_src+1 < rows && mu[r_src+1][c_src] == 0) {
		if(!vis[r_src+1][c_src])
			DFSUtil(mu, cc, vis, r_src+1, c_src, cc_num);
		num_adj --;
	}
	if(r_src-1 >= 0 && mu[r_src-1][c_src] == 0) {
		if(!vis[r_src-1][c_src])
			DFSUtil(mu, cc, vis, r_src-1, c_src, cc_num);
		num_adj --;
	}
	if(c_src+1 < cols && mu[r_src][c_src+1] == 0) {
		if(!vis[r_src][c_src+1])
			DFSUtil(mu, cc, vis, r_src, c_src+1, cc_num);
		num_adj --;
	}
	if(c_src-1 >= 0 && mu[r_src][c_src-1] == 0) {
		if(!vis[r_src][c_src-1])
			DFSUtil(mu, cc, vis, r_src, c_src-1, cc_num);
		num_adj --;
	}
	cc_pic[cc_num] += num_adj;
	return;
}

ll DFS(vvi & mu, vvi & cc) {
	ll rows = mu.size();
	ll cols = mu[0].size();
	ll cc_num = 1;
	vector<vector<bool> > vis(rows, vector<bool> (cols, false));
	for(ll i=0; i<rows; i++) {
		for(ll j=0; j<cols; j++) {
			if(mu[i][j] != 1 && !vis[i][j]) {
				// cout << "Calling DFS on " << i << " " << j << endl;
				DFSUtil(mu, cc, vis, i, j, cc_num);
				// cout << "CC_num = " << cc_num << endl;
				// cout << "CC_pic = " << cc_pic[cc_num] << endl;
				cc_num++;
			}
		}
	}
	return cc_num;
}

int main(int argc, char ** argv) {

	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	vvi mu(n, vi(m,0));
	// 0 means empty, 1 means wall
	for(ll i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		for(ll j=0; j<m; j++) {
			if(tmp[j] == '.') mu[i][j] = 0;
			else mu[i][j] = 1;
		}
	}
	vvi cc(n, vi(m,-1));
	ll cc_num = DFS(mu, cc);
	/*
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			cout << cc[i][j] << "\t";
		}
		cout <<  endl;
	}
	*/
	ll r, c;
	for(ll i=0; i<k; i++) {
		cin >> r >> c;
		r -- ;
		c -- ;
		cout << cc_pic[coord_cc[ii(r,c)]] << endl;
	}
	return 0;
}
