// http://codeforces.com/problemset/problem/122/A
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool islucky(ll x){
	if(x == 0) return false;
	ll tmp = x;
	while(tmp != 0){
		if((tmp%10) == 4 || (tmp%10) == 7);
		else return false;
		tmp = tmp/10ll;
	}
	return true;
}

int main(int argc, char ** argv){
	ll n;
	cin >> n;
	for(ll i=1; i<=n; i++){
		if(islucky(i) && (n%i == 0)){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
