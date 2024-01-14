// https://codeforces.com/contest/612/problem/A

#include <bits/stdc++.h>

using namespace std;

void print_ans(string s, int p, int q, int i, int j) {
    cout << i+j << endl;
    for (int m1 = 0; m1 < i; m1++) {
	cout << s.substr(m1*p, p) << endl;
    }
    for (int m2 = 0; m2 < j; m2++) {
	cout << s.substr(p*i+m2*q, q) << endl;
    }
}

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;

    for (int i = 0; i <= (n/q); i++) {
	if ((n-i*q)%p == 0) {
	    print_ans(s, p, q, (n-i*q)/p, i);
	    return 0;
	}
    }
    cout << "-1" << endl;
    return 0;
}
