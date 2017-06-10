#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(int argc, char ** argv) {
	ll N;
	cin >> N;
	vi a(N,0);
	for(ll i=0; i<N; i++) cin >> a[i];
	sort(a.begin(), a.end());
	cout << a[N-1] - a[0] << endl;
	return 0;
}
