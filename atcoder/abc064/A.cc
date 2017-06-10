#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main(int argc, char ** argv) {
	ll r, g, b;
	cin >> r >> g >> b;
	ll ans = 100*r + 10*g + b;
	if(ans%4 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
