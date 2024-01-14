#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(int argc, char ** argv){
	ll sum = 0;
	ll n;
	cin >> n;
	vector<ll> a(n,0), cnt(n,0), sum_cnt(n,0);
	for(ll i=0; i<n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum%3 != 0){
		cout << 0 << endl;
		return 0;
	}
	ll sum2 = 0;
	for(ll i=(n-1); i>=0; i--){
		sum2 += a[i];
		if(sum2 == (sum/3)) cnt[i] = 1;
	}
	for(ll i=(n-1); i>=0; i--){
		if(i == n-1) sum_cnt[i] = cnt[i];
		else sum_cnt[i] = sum_cnt[i+1]+cnt[i];
	}
	// cnt[i] = 1 if a[i]+...+a[n-1] == sum/3; 0 otherwise
	// sum_cnt[i] = cnt[i]+cnt[i+1]+...+cnt[n-1]
	sum2 = 0;
	ll num_ways = 0;
	for(ll i=0; i<n-2; i++){
		sum2 += a[i];
		if(sum2 == (sum/3)){
			num_ways += sum_cnt[i+2];
		}
	}
	cout << num_ways << endl;

	return 0;
}
