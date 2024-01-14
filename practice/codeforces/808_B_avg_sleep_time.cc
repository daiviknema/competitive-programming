#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(int argc, char ** argv) {

	ll n, k;
	cin >> n >> k;
	vi a(n,0);
	ll running_sum = 0;
	ll total = 0;
	for(ll i=0ll; i<n; i++) {
		cin >> a[i];
		if(i<k) {
			running_sum += a[i];
			total = running_sum;
		} else {
			running_sum += a[i];
			running_sum -= a[i-k];
			total += running_sum;
		}
	}
	double avg = (double)total/(double)(n-k+1);
	cout << setprecision(15) << avg << endl;


	return 0;
}
