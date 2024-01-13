// https://codeforces.com/problemset/problem/455/A

#include <bits/stdc++.h>

using namespace std;

long long int dp[100001], a[100001], freq[100001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	freq[a[i]]++;
    }
    dp[0] = 0;
    dp[1] = freq[1];

    for (int i = 2; i < 100001; i++) {
	dp[i] = max(dp[i-1], i*freq[i]+dp[i-2]);
    }
    cout << dp[100000] << endl;
    return 0;
}
