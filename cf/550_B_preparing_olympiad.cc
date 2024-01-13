// https://codeforces.com/contest/550/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> difficulty(n, 0);
    for (int i = 0; i < n; i++) cin >> difficulty[i];
    int bitmask = (1 << n);
    int valid_choice = 0;
    while (bitmask--) {
	int min_difficulty = 1000000000+3;
	int max_difficulty = 0;
	int total_dif = 0;
	int num_probs = 0;
	for (int i = 0; i < n; i++) {
	    if (bitmask & (1<<i)) {
		num_probs++;
		total_dif += difficulty[i];
		min_difficulty = min(min_difficulty, difficulty[i]);
		max_difficulty = max(max_difficulty, difficulty[i]);
	    }
	}

	if (num_probs >= 2 && total_dif >= l && total_dif <= r && (max_difficulty - min_difficulty) >= x) {
	    valid_choice++;
	}
    }
    cout << valid_choice << endl;
    return 0;
}
