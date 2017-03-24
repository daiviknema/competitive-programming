// http://codeforces.com/problemset/problem/550/A
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(int argc, char ** argv){
	string s;
	cin >> s;
	ll idx1 = -1, idx2 = -1;
	ll n = s.length();
	for(ll i=0; i<n-1; i++){
		if(s[i] == 'A' && s[i+1] == 'B'){
			idx1 = i;
			break;
		}
	}
	for(ll i=n-1; i>0; i--){
		if(s[i] == 'A' && s[i-1] == 'B'){
			idx2 = i-1;
			break;
		}
	}
	if(idx1 == -1 || idx2 == -1){
		cout << "NO" << endl;
		return 0;
	}
	if(idx2 > idx1+1){
		cout << "YES" << endl;
		return 0;
	}
	idx1 = -1; idx2 = -1;
	for(ll i=0; i<n-1; i++){
		if(s[i] == 'B' && s[i+1] == 'A'){
			idx1 = i;
			break;
		}
	}
	for(ll i=n-1; i>0; i--){
		if(s[i] == 'B' && s[i-1] == 'A'){
			idx2 = i-1;
			break;
		}
	}
	if(idx1 == -1 || idx2 == -1){
		cout << "NO" << endl;
		return 0;
	}
	if(idx2 > idx1+1){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
