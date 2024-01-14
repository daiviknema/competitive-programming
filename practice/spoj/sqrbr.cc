#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main(int argc, char ** argv) {
	ll d;
	cin >> d;
	while(d--) {
		ll n, k;
		cin >> n >> k;
		vi s(k, 0);
		vector<bool> fixed(2*n, false);
		for(ll i=0; i<k; i++) {
			cin >> s[i];
			s[i] --;
			fixed[s[i]] = true;
		}
		// dp[i][j] = number of valid bracketed strings of length i, such that num('[') - num(']') == j.
		// dp[i][j] = 0 (for all j > i)
		// dp[i][i] = 1
		// dp[1][1] = 1
		// dp[1][i] = 0 for all i>1
		// if i is fixed: dp[i][0] = 0 and dp[i][j] = dp[i-1][j-1]
		// else: dp[i][0] = dp[i-1][1] and dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1]
		vvi dp(2*n+1, vi(2*n+1, 0));
		for(ll i=1; i<=2*n; i++) {
			for(ll j=0; j<=i; j++) {
				if(i == 1) {
					if(j == 1) dp[i][j] = 1;
				} else {
					if(fixed[i-1]) {
						if(j > 0) dp[i][j] = dp[i-1][j-1];
						else dp[i][j] = 0;
					} else {
						if(j == 0) dp[i][j] = dp[i-1][1];
						else {
							if(j != 2*n) dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
							else dp[i][j] = dp[i-1][j-1];
						}
					}
				}
			}
		}
		/*
		for(ll i=0; i<=2*n; i++) {
			for(ll j=0; j<=2*n; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << dp[2*n][0] << endl;
	}
	return 0;
}
