// https://codeforces.com/problemset/problem/630/I
#include <bits/stdc++.h>

using namespace std;

// recursive exponentiation
long long int binexp_rec(long long int a, long long int exp) {
    if (exp == 0) return 1;
    long long int ret = binexp_rec(a, exp/2);
    return (exp % 2) ? ret * ret * a : ret * ret;
}

// iterative exponentation
long long int binexp_iter(long long int a, long long int exp) {
    long long int ret = 1;
    long long int cur = a;
    while (exp != 0) {
	if (exp & 1 == 1) {
	    ret = ret * cur;
	}
	cur = cur * cur;
	exp = exp >> 1;
    }
    return ret;
}

int main() {
    // for (long long int i = 0; i < 10; i ++) {
    //     cout << "Recursive 2^" << i << " " << binexp_rec(2, i) << endl;
    //     cout << "Iterative 2^" << i << " " << binexp_iter(2, i) << endl;
    //     cout << endl;
    // }
    long long int n;
    cin >> n;
    cout << binexp_rec(4, n-3)*(9*n - 3) << endl;
    // cout << binexp_iter(4, n-3)*(9*n - 3) << endl;
    return 0;
}
