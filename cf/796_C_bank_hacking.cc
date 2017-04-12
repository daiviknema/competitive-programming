#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector< vector<ll> > al_t;

int main(int argc, char ** argv){
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	map<ll,ll> str_cnt;
	vi a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
		str_cnt[a[i]+2] += 1;
	}
	al_t al(n);
	for(int i=0; i<(n-1); i++){
		ll u,v;
		cin >> u >> v;
		u--; v--;
		al[u].push_back(v);
		al[v].push_back(u);
	}
	ll ans = 1e16;
	for(int i=0; i<n; i++){
		if(str_cnt[a[i]+2] > 1) str_cnt[a[i]+2] -= 1;
		else str_cnt.erase(a[i]+2);
		str_cnt[a[i]] += 1;
		for(vector<ll>::iterator iter=al[i].begin(); iter != al[i].end(); iter++){
			if(str_cnt[a[*iter]+2]>1) str_cnt[a[*iter]+2] -= 1;
			else str_cnt.erase(a[*iter]+2);
			str_cnt[a[*iter]+1] += 1;
		}
		ans = min(ans,str_cnt.rbegin()->first);
		str_cnt[a[i]+2] += 1;
		if(str_cnt[a[i]] > 1) str_cnt[a[i]] -= 1;
		else str_cnt.erase(a[i]);
		for(vector<ll>::iterator iter=al[i].begin(); iter != al[i].end(); iter++){
			str_cnt[a[*iter]+2] += 1;
			if(str_cnt[a[*iter]+1]>1) str_cnt[a[*iter]+1] -= 1;
			else str_cnt.erase(a[*iter]+1);
		}
	}
	cout << (ans) << endl;

	return 0;
}
