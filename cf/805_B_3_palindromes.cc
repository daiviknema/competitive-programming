#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(int argc, char ** argv) {
	ll n;
	cin >> n;
	for(int i=0; i<n; i++) {
		if(i%4 == 0 || i%4 == 1) {
			cout << "a";
		} else {
			cout << "b";
		}
	}
	cout << endl;
	return 0;
}
