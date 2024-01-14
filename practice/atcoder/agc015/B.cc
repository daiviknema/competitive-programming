#include <iostream>
#include <vector>
#include <string>

using namespace std;


typedef long long ll;

int main(int argc, char ** argv) {
	string s;
	cin >> s;
	ll sum = 0;
	ll n = s.length();
	for(ll i=0; i<s.length(); i++) {
		if(i == 0)
			sum += n-1;
		else if(i == n-1)
			sum += n-1;
		else {
			if(s[i] == 'U') {
				sum += n-1-i;
				sum += 2*i;
			}else if(s[i] == 'D') {
				sum += i;
				sum += 2*(n-i-1);
			}
		}
	}
	cout << sum << endl;
	return 0;
}
