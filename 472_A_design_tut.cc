// http://codeforces.com/problemset/problem/472/A
#include <iostream>

using namespace std;

typedef long long ll;

int main(int argc, char ** argv){
	ll n;
	cin >> n;
	if (n%2 == 0) cout << "4 " << (n-4) << endl;
	else cout << "9 " << (n-9) << endl;
	return 0;
}
