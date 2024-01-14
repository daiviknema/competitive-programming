// https://codeforces.com/contest/612/problem/D

#include <bits/stdc++.h>

using namespace std;

struct event {
    int x;
    int val;

    event(int x, int val) : x(x), val(val) {};
};

vector<pair<int, int>> find_min_segments(vector<event>& events, int k) {
    // sort events by x pos
    sort(events.begin(), events.end(), [](const event& lhs, const event& rhs) {
	return ((lhs.x < rhs.x) || (lhs.x == rhs.x && lhs.val > rhs.val));
    });

    vector<pair<int, int>> ans;

    int cur_overlap_segments = 0;
    int left = -1000000011, right = -1000000011;
    for (int i = 0; i < events.size(); i++) {
	int new_overlap_segments = cur_overlap_segments + events[i].val;
	if (new_overlap_segments > k) {
	    // nothing to be done
	} else if (cur_overlap_segments == k-1 && new_overlap_segments == k) {
	    // current point is left
	    left = events[i].x;
	} else if (cur_overlap_segments == k && new_overlap_segments == k-1) {
	    // current point is right
	    right = events[i].x;
	    ans.push_back({left, right});
	}
	cur_overlap_segments = new_overlap_segments;
    }

    return ans;
}

int main() {
    int m, k;
    cin >> m >> k;

    vector<event> events;
    for (int i = 0; i < m; i++) {
	int a, b;
	// cin >> a >> b;
	scanf("%d",&a);
	scanf("%d",&b);
	events.push_back(event(a, 1));
	events.push_back(event(b, -1));
    }

    vector<pair<int, int>> ans = find_min_segments(events, k);

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
	cout << ans [i].first << " " << ans[i].second << endl;
    }
    return 0;
}
