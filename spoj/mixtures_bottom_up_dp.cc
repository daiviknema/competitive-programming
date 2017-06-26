// MIXTURES - Bottom up DP.
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000+9;

int main(int argc, char ** argv) {
	ll n;
	while(cin >> n) {
		vi a(n,0);
		vi pre(n,0);
		for(ll i=0; i<n; i++) {
			cin >> a[i];
			if(i == 0) pre[i] = a[i];
			else pre[i] = a[i]+pre[i-1];
		}
		vvi dp(n, vi(n+1, inf));
		// dp[i][j] = dp[i][k]+dp[k+1][j]+F(i,k,k+1,j)
		// dp[i][len] = dp[i][len-p] + dp[i+p][p] + F(i,len-p-1,len-p,len-1)
		for(ll len = 1; len<=n; len++) {
			if(len == 1) {
				for(ll i=0; i<n; i++)
					dp[i][len] = 0;
			//} else if(len == 2) {
			// 	for(ll i=0; i<n-1; i++)
			//		dp[i][len] = a[i]*a[i+1];
			} else {
				for(ll i=0; i<n; i++) {
					if(i+len > n);
					else {
						for(ll p = 1; p<len; p++) {
							ll rem_smoke = ((pre[i+len-p-1]-pre[i]+a[i])%100)*((pre[i+len-1] - pre[i+len-p] + a[i+len-p])%100);
							dp[i][len] = min(dp[i][len-p]+dp[i+len-p][p]+rem_smoke, dp[i][len]);
						}
					}
				}
			}
		}
		cout << dp[0][n] << endl;
	}
	return 0;
}
