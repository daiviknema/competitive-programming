#include <iostream>
#include <vector>
#include <string>

using namespace std;

int edit_distance(string & a, int n, string & b, int m) {
	if(n < 0) return m+1;
	if(m < 0) return n+1;
	if(a[n] == b[m]) {
		return edit_distance(a, n-1, b, m-1);
	} else {
		return 1+min(\
				edit_distance(a, n, b, m-1),\
				min( edit_distance(a, n-1, b, m),\
				edit_distance(a, n-1, b, m-1))\
				);
	}
}

int edit_distance_memoized(string & a, int n, string & b, int m, vector< vector<int> > & dp) {
    if(n < 0) {
        return m+1;
    }
	if(m < 0) {
        return n+1;
    }
	if(dp[n][m]!=-1) return dp[n][m];
	if(a[n] == b[m]) {
		dp[n][m] = edit_distance_memoized(a, n-1, b, m-1, dp);
	} else {
		dp[n][m] = 1+min(\
				edit_distance_memoized(a, n, b, m-1, dp),\
				min( edit_distance_memoized(a, n-1, b, m, dp),\
				edit_distance_memoized(a, n-1, b, m-1, dp))\
				);
	}
    return dp[n][m];
}

int edit_distance_bottom_up(string & a, string & b) {
	// dp[n][m] = edit disance between a[0:n+1] and b[0:m+1]
	// dp[n][m] = 1+dp[n-1][m-1] if a[n-1] == b[m-1]
	// dp[n][m] = 1+min(dp[n][m-1], dp[n-1][m], dp[n-1][m-1])
	// dp[0][m] = m
	// dp[n][0] = n
	vector< vector<int> > dp(a.length()+1, vector<int> (b.length()+1, 0));
	for(int len_a = 0; len_a <= a.length(); len_a ++) {
		dp[len_a][0] = len_a;
	}
	for(int len_b = 0; len_b <= b.length(); len_b ++) {
		dp[0][len_b] = len_b;
	}
	for(int len_a=1; len_a <= a.length(); len_a++) {
		for(int len_b=1; len_b <= b.length(); len_b++) {
			if(a[len_a-1] == b[len_b-1]) {
				dp[len_a][len_b] = dp[len_a-1][len_b-1];
			} else {
				dp[len_a][len_b] = 1+min(dp[len_a-1][len_b], min(dp[len_a][len_b-1], dp[len_a-1][len_b-1]));
			}
		}
	}
	return dp[a.length()][b.length()];
}

int main(int argc, char ** argv) {
	string a, b;
	cin >> a >> b;
	vector< vector<int> > dp(a.length(), vector<int> (b.length(), -1));
	cout << edit_distance(a, a.length()-1, b, b.length()-1) << endl;
	cout << edit_distance_memoized(a, a.length()-1, b, b.length()-1, dp) << endl;
	cout << edit_distance_bottom_up(a, b) << endl;
	return 0;
}
