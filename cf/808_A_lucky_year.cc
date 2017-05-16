#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(int argc, char ** argv) {

	ll n;
	cin >> n;
	ll og = n;
	// extract most significant digit
	ll tmp = n%10;
	int num_dig = 0;
	while(n != 0) {
		tmp = n%10;
		n = n/10;
		num_dig ++;
	}
	// cout << tmp+1;
	tmp = tmp+1;
	for(int i=1; i<num_dig; i++) {
		tmp = tmp*10;
	}
	cout << (tmp-og) << endl;

	return 0;
}
