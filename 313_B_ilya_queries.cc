// http://codeforces.com/problemset/problem/313/B
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(int argc, char ** argv){
	string s;
	cin >> s;
	ll m;
	cin >> m;
	ll n = s.length();
	vector <ll> dp(n+1,0);
	for (ll i=0; i<n; i++){
		if (i==0) dp[i] = 0;
		else{
			if (s[i] == s[i-1]) dp[i] = dp[i-1]+1;
			else dp[i] = dp[i-1];
		}
	}
	for (ll i=0; i<m; i++){
		ll l,r;
		cin >> l >> r;
		cout << dp[r-1]-dp[l-1] << endl;
	}
	return 0;
}
