#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(int argc, char ** argv){
	ll n;
	cin >> n;
	vector <ll> m(n,0);
	ll sum = 0;
	for(ll i=0; i<n; i++){
		cin >> m[i];
		sum += m[i];
	}
	sort(m.begin(),m.end());
	ll av_floor = sum/n;
	ll remaining = sum - av_floor*n;
	ll seconds = 0;
	for(ll i=n-1; i>=0; i--){
		if(remaining!=0){
			seconds += abs(m[i]-av_floor-1);
			m[i] = av_floor+1;
			remaining--;
		}else{
			seconds += abs(m[i]-av_floor);
			m[i] = av_floor;
		}
	}
	cout << seconds/2 << endl;
	return 0;
}
