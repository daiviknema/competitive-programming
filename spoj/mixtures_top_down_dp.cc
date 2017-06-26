// MIXTURES - Top down DP. Gets AC.
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;


const ll N_MAX = 103;
const ll inf = 1000000000+9;

ll dp[N_MAX][N_MAX];
bool marked[N_MAX][N_MAX];

ll solve(vi & a, vi & pre, ll beg, ll end) {
	if(marked[beg][end]) return dp[beg][end];
	if(beg == end) {
		dp[beg][end] = 0;
		marked[beg][end] = true;
		return dp[beg][end];
	}
	else if(beg+1 == end) {
		dp[beg][end] = a[beg]*a[end];
		marked[beg][end] = true;
		return dp[beg][end];
	}
	ll ans = inf;
	for(ll i=beg; i<end; i++) {
		ans = min(ans, solve(a, pre, beg, i) + solve(a, pre, i+1, end) + ((pre[end]- pre[i])%100)*((pre[i]-pre[beg]+a[beg])%100));
	}
	dp[beg][end] = ans;
	marked[beg][end] = true;
	return dp[beg][end];
}

int main(int argc, char ** argv) {
	ll n;
	while(cin >> n) {
		memset(dp, 0, sizeof dp);
		memset(marked, false, sizeof marked);
		vi a(n,0), pre(n,0);
		for(ll i=0; i<n; i++) {
			cin >> a[i];
			if(i == 0) pre[i] = a[i];
			else pre[i] = pre[i-1] + a[i];
		}
		cout << solve(a, pre, 0, n-1) << endl;
	}

	return 0;
}
