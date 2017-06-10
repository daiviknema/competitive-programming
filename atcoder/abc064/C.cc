#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main(int argc, char ** argv) {
	ll n;
	cin >> n;
	vi a(n,0);
	vector<bool> col(8, false);
	ll num_pros = 0;
	for(ll i=0; i<n; i++) {
		cin >> a[i];
		if(a[i] < 3200) col[a[i]/400] = true;
		else num_pros++;
	}
	ll min_cols = 0;
	for(ll i=0; i<8; i++) if(col[i]) min_cols++;
	if(min_cols == 0) cout << 1 << " " << num_pros << endl;
	else cout << min_cols << " " << min_cols+num_pros << endl;
	return 0;
}
