#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N_MAX = 10000;
const int XOR_MAX = 1029;
const int MOD = 1000000000+7;

int main(int argc, char ** argv) {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int price[N_MAX];
		for(int i=0; i<n; i++) {
			cin >> price[i];
		}
		int subset = 0;
		int xorsum[XOR_MAX];
		memset(xorsum, 0, sizeof xorsum);
		while(subset < (1<<n)) {
			int tmp = subset;
			int i = 0;
			int cur_xor = 0;
			while(tmp != 0) {
				if(tmp%2 == 1) {
					// cout << i << " ";
					cur_xor ^= price[i];
				}
				tmp = tmp >> 1;
				i ++;
			}
			xorsum[cur_xor] ++;
			// cout << endl;
			subset ++;
		}
		int ans = 0;
		for(int i=0; i<XOR_MAX; i++) {
			if(xorsum[i] > 1) {
				// cout << "xorsum[" << i <<"] = " << xorsum[i] << endl;
				ans += ((((xorsum[i]*(xorsum[i]-1))/2)%MOD)*2)%MOD;
				ans %= MOD;
			}
		}
		ans += 1;
		ans %= MOD;
		cout << ans << endl;

	}
	return 0;
}
