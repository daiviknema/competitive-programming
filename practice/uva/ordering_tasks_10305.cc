#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
 
vi toposort;
 
void DFSUtil(vvi & al, ll src, vector<bool> & vis) {
	vis[src] = true;
	for(ll i=0; i<al[src].size(); i++) {
		if(!vis[al[src][i]])
			DFSUtil(al, al[src][i], vis);
	}
	toposort.push_back(src);
}
 
 
void DFS(vvi & al) {
	vector<bool> vis(al.size(), false);
	for(ll i=0; i<al.size(); i++) {
		if(!vis[i]) {
			DFSUtil(al, i, vis);
		}
	}
}
 
int main(int argc, char ** argv) {
	while(true) {
		ll n, m;
		cin >> n >> m;
		if(n == m && m == 0) {
			break;
		}
		vvi al(n);
		for(ll i=0; i<m; i++) {
			ll a, b;
			cin >> a >> b;
			a -- ;
			b -- ;
			al[a].push_back(b);
		}
		DFS(al);
		for(ll i=toposort.size()-1; i>=0; i--) {
			cout << toposort[i]+1 << " ";
		}
		cout << endl;
		toposort.clear();
	}
	return 0;
}
