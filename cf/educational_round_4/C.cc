// https://codeforces.com/contest/612/problem/C

#include <bits/stdc++.h>

using namespace std;

bool is_open(char ch) {
    return (ch == '{' || ch == '(' || ch == '<' || ch == '[');
}

bool is_close(char ch) {
    return (ch == '}' || ch == ')' || ch == '>' || ch == ']');
}

bool is_match(char ch1, char ch2) {
    return ((ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']') || (ch1 == '<' && ch2 == '>') || (ch1 == '(' && ch2 == ')'));
}

int main() {
    stack<char> st;

    string s;
    cin >> s;

    int num_repl = 0;
    for (char ch : s) {
	if (is_open(ch)) {
	    st.push(ch);
	} else if (is_close(ch)) {
	    if (st.empty()) {
		cout << "Impossible" << endl;
		return 0;
	    }
	    if (is_match(st.top(), ch)) {
		st.pop();
	    } else {
		num_repl ++;
		st.pop();
	    }
	}
    }

    if (!st.empty()) {
	cout << "Impossible" << endl;
	return 0;
    }

    cout << num_repl << endl;
    return 0;
}
