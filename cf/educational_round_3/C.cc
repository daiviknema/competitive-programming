#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> m(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
	cin >> m[i];
	sum += m[i];
    }

    int final_load = sum / n;
    int extra = sum % n;

    int ans = 0;
    sort(m.rbegin(), m.rend());
    for (int i = 0; i < n; i++) {
	if (extra > 0) {
	    ans += abs(m[i]-final_load -1);
	    extra--;
	} else {
	    ans += abs(m[i] - final_load);
	}
    }
    cout << ans/2 << endl;
    return 0;
}
