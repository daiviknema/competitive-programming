#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main(int argc, char ** argv) {
	ios_base::sync_with_stdio(false);
	ll n, m, q;
	cin >> n >> m >> q;
	vvi s(n, vi(m,0));
	for(ll i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		for(ll k=0; k<tmp.length(); k++) {
			if(tmp[k] == '0') s[i][k] = 0;
			if(tmp[k] == '1') s[i][k] = 1;
		}
	}
	vvi v(n, vi(m,0));
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			ll A=0, B=0, C=0;
			if(i > 0) A = v[i-1][j];
			if(j > 0) B = v[i][j-1];
			if(i > 0 && j > 0) C = v[i-1][j-1];
			v[i][j] = s[i][j] + A + B - C;
		}
	}
	vvi ev(n, vi(m,0)), eh(n, vi(m,0));
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			ll A=0, B=0, C=0, D=0;
			if(i > 0) D = s[i][j]&s[i-1][j];
			if(i > 0) A = ev[i-1][j];
			if(j > 0) B = ev[i][j-1];
			if(i > 0 && j > 0) C = ev[i-1][j-1];
			ev[i][j] = D + A + B - C;
		}
	}
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			ll A=0, B=0, C=0, D=0;
			if(j > 0) D = s[i][j]&s[i][j-1];
			if(i > 0) A = eh[i-1][j];
			if(j > 0) B = eh[i][j-1];
			if(i > 0 && j > 0) C = eh[i-1][j-1];
			eh[i][j] = D + A + B - C;
		}
	}
	/*
	cout << "v" << endl;
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << "ev" << endl;
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			cout << ev[i][j] << " ";
		}
		cout << endl;
	}
	cout << "eh" << endl;
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			cout << eh[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for(ll i=0; i<q; i++) {
		ll x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 --; x2 --;
		y1 --; y2 --;
		ll A_v = v[x2][y2];
		ll A_ev = ev[x2][y2];
		ll A_eh = eh[x2][y2];
		ll B_v = 0, C_v = 0, D_v = 0;
		ll B_ev = 0, C_ev = 0, D_ev = 0;
		ll B_eh = 0, C_eh = 0, D_eh = 0;
		if(x1 > 0 && y1 > 0) {
			B_v = v[x1-1][y1-1];
		}
		if(x1 > 0) {
			B_eh = eh[x1-1][y1];
			C_v = v[x1-1][y2];
			C_eh = eh[x1-1][y2];
		}
		if(y1 > 0) {
			B_ev = ev[x1][y1-1];
			D_v = v[x2][y1-1];
			D_ev = ev[x2][y1-1];
		}
		C_ev = ev[x1][y2];
		D_eh = eh[x2][y1];
		ll num_v = A_v + B_v - C_v - D_v;
		ll num_ev = A_ev + B_ev - C_ev - D_ev;
		ll num_eh = A_eh + B_eh - C_eh - D_eh;
		// cout << "num_v : " << num_v << endl;
		// cout << "num_ev : " << num_ev << endl;
		// cout << "num_eh : " << num_eh << endl;
		ll ans = num_v - num_ev - num_eh;
		cout << ans << endl;
	}

	return 0;
}
