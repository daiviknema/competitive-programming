// This is a O(n*m*m) solution. While this gets AC, there also exists a 
// more efficient O(n*m) solution
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main(int argc, char ** argv) {
	ios_base::sync_with_stdio(false);
	while(true) {
		ll n, m;
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		vvi y(n, vi(m,0));
		vvi pre_y(n, vi(m,0));
		vvi b(n, vi(m,0));
		vvi pre_b(n, vi(m,0));
		for(ll i=0; i<n; i++) {
			for(ll j=0; j<m; j++) {
				cin >> y[i][j];
				if(j > 0) pre_y[i][j] = pre_y[i][j-1]+y[i][j];
				else pre_y[i][j] = y[i][j];
			}
		}
		for(ll i=0; i<n; i++) {
			for(ll j=0; j<m; j++) {
				cin >> b[i][j];
				if(j > 0) pre_b[i][j] = pre_b[i][j-1]+b[i][j];
				else pre_b[i][j] = b[i][j];
			}
		}
		/*
		for(ll i=0; i<n; i++) {
			for(ll j=0; j<m; j++) {
				cout << pre_y[i][j] << " ";
			}
			cout << endl;
		}
		for(ll i=0; i<n; i++) {
			for(ll j=0; j<m; j++) {
				cout << pre_b[i][j] << " ";
			}
			cout << endl;
		}
		*/
		vvi dp(n, vi(m+1,-1));
		for(ll i=0; i<n; i++) {
			for(ll j=0; j<=m; j++) {
				if(i == 0) {
					if(j == 0) {
						dp[i][j] = pre_b[i][m-1];
					} else {
						dp[i][j] = (pre_b[i][m-1] - pre_b[i][j-1]) + pre_y[i][j-1];
					}
				} else {
					if(j == 0) {
						dp[i][j] = pre_b[i][m-1] + dp[i-1][j];
					} else {
						for(ll k=0; k<=j; k++) {
							dp[i][j] = max(dp[i][j], dp[i-1][k]+pre_y[i][j-1]+pre_b[i][m-1]-pre_b[i][j-1]);
						}
					}
				}
			}
		}
		/*
		for(ll i=0; i<n; i++) {
			for(ll j=0; j<m; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		*/
		ll ans = -1;
		for(ll i=0; i<=m; i++) {
			if(dp[n-1][i] > ans) ans = dp[n-1][i];
		}
		cout << ans << endl;
	}
	return 0;
}
