#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(int argc, char ** argv) {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	stack<char> st;
	for(ll i=0; i<n; i++) {
		if(s[i] == '(') {
			st.push('(');
		} else if(s[i] == ')' && !st.empty() && st.top() == '(') {
			st.pop();
		} else if(s[i] == ')' && !st.empty() && st.top() == ')') {
			st.push(')');
		} else if(s[i] == ')' && st.empty()) {
			st.push(')');
		}
	}
	ll num_beg = 0, num_end = 0;
	while(!st.empty() && st.top() == '(') {
		num_end++;
		st.pop();
	}
	while(!st.empty() && st.top() == ')') {
		num_beg++;
		st.pop();
	}
	for(ll i=0; i<num_beg; i++) {
		cout << "(";
	}
	cout << s;
	for(ll i=0; i<num_end; i++) {
		cout << ")";
	}
	cout << endl;
	return 0;
}
