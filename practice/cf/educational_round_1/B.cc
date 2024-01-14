#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

string shift(string s, ll l, ll r, ll k) {
	string ans = s;
	l--;
	r--;
	char arr[10005];
	memset(arr, 0, sizeof arr);
	for(ll i=r-k+1; i<=r; i++) {
		arr[i-(r-k+1)] = s[i];
	}
	for(ll i=r-k; i>=l; i--) {
		ans[i+k] = ans[i];
	}
	for(ll i=l; i<l+k; i++) {
		ans[i] = arr[i-l];
	}

	return ans;
}

int main(int argc, char ** argv) {

	string s;
	cin >> s;
	ll m;
	cin >> m;
	while(m--) {
		ll l, r, k;
		cin >> l >> r >> k;
		k = k%(r-l+1);
		s = shift(s, l, r, k);
	}
	cout << s << endl;

	return 0;
}
