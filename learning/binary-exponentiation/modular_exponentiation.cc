// https://codeforces.com/problemset/problem/913/A
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int x = 0;
    long long int m, n;
    cin >> n >> m;
    if (n <= 30ll) cout << m % (1ll<<n) << endl;
    else cout << m << endl;
    return 0;
}
