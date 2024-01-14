/**
 * Difficulty: Easy
 * Status: AC
 * Time: 4 min 32 sec
 */
#include <iostream>
#include <string>
#include <vector>

typedef long long int ll;

using namespace std;

int main() {
	int N, tmp, sum = 0;
	cin >>N;
	for (int i = 0; i<N; i++) {
		cin >> tmp;
		sum += tmp;
	}

	string ans = (sum == (int)(N*(N+1))/2) ? "YES" : "NO";
	cout << ans << endl;
}
