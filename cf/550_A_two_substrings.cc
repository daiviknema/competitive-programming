// https://codeforces.com/problemset/problem/550/A

#include <bits/stdc++.h>

using namespace std;

int find_first(const string& s, int beg, const string& to_find) {
    for (int i = beg; i < s.length(); i++) {
	if (s.substr(i, to_find.length()) == to_find)
	    return i;
    }
    return s.length();
}

int main() {
    string s;
    cin >> s;

    int ab_idx = find_first(s, 0, "AB");
    int ba_idx = find_first(s, ab_idx+2, "BA");

    if (ab_idx < s.length() && ba_idx < s.length()) {
	cout << "YES";
	return 0;
    }


    ba_idx = find_first(s, 0, "BA");
    ab_idx = find_first(s, ba_idx+2, "AB");

    if (ab_idx < s.length() && ba_idx < s.length()) {
	cout << "YES";
	return 0;
    }

    cout << "NO";
    return 0;
}
