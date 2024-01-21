// https://codeforces.com/contest/616/problem/D

#include <bits/stdc++.h>

using namespace std;

pair<int, int> find_longest_k_good_seq(const vector<int>& a, int k) {
    pair<int, int> ans;
    ans.first = 0; ans.second = 0;

    unordered_map<int, int> window_elems_cnt;
    window_elems_cnt[a[0]]++;

    int r = 0; int l = 0;
    for (l = 0, r = 0; l <= r && window_elems_cnt.size() <= k && r < a.size(); ) {
	// update max window
	if (r - l >= ans.second - ans.first) {
	    ans.first = l;
	    ans.second = r;
	}

	// expand window
	r++;
	window_elems_cnt[a[r]]++;

	// while window is bad, contract window
	for (; l <= r && window_elems_cnt.size() > k; l++) {
	    window_elems_cnt[a[l]]--;
	    if (!window_elems_cnt[a[l]]) window_elems_cnt.erase(a[l]);
	}
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }

    pair<int, int> ans = find_longest_k_good_seq(a, k);

    cout << ans.first+1 << " " << ans.second+1 << endl;
    return 0;
}
