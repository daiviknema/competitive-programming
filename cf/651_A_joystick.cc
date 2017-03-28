// http://codeforces.com/problemset/problem/651/A
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll N = 305;

int main(int argc, char ** argv){
	vector <vector <ll> > dp(N, vector <ll> (N, 0));
	for(ll k=0; k<(2*N - 1); k++){
		ll max_i = min(N-1ll,k);
		ll min_i = max(0ll,k-N+1ll);
		for(ll i = min_i, j = max_i; i <= max_i; i++, j--){
			if (i == 0 || j == 0){
				dp[i][j] = 0;
			}else{
				ll p1 = 0, p2 = 0;
				if(i-2 >= 0 && j+1 < N) p1 = dp[i-2][j+1];
				if(i+1 < N && j-2 >= 0) p2 = dp[i+1][j-2];
				dp[i][j] = 1+max(p1,p2);
			}
		}
	}
	/*
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	dp[1][1] = 0;
	ll a1,a2;
	cin >> a1 >> a2;
	cout << dp[a1][a2] << endl;
	return 0;
}

// Naive solution -- TLE for sure
/*
ll p(ll a1, ll a2){
	if(a1 <= 0 || a2 <= 0) return 0;
	return 1+max(p(a1+1,a2-2),p(a1-2,a2+1));
}

int main(int argc, char ** argv){
	ll a1, a2;
	cin >> a1 >> a2;
	ll ans = p(a1,a2);
	cout << ans << endl;
	return 0;
}
*/
