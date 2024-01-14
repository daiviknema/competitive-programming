#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(int argc, char ** argv) {
	ll n;
	cin >> n;
	vi before(n,0), after(n,0);
	bool any_change = false;
	for(int i=0; i<n; i++) {
		cin >> before[i] >> after[i];
		if(after[i] != before[i]) any_change = true;
	}
	if(any_change) {
		cout << "rated" << endl;
	} else {
		bool strictly_decreasing = true;
		for(int i=0; i<n-1; i++) {
			if(after[i+1] <= after[i]) {
			} else {
				strictly_decreasing = false;
			}
		}
		if(strictly_decreasing) {
			cout << "maybe" << endl;
		} else {
			cout << "unrated" << endl;
		}
	}
	return 0;
}
