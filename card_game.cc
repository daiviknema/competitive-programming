#include <iostream>

using namespace std;

const int inf = 1000000000+9;

int get_num(int * arr, int num_elem) {
	int ans = 0;
	for(int i=0; i<num_elem; i++) {
		ans *= 10;
		ans += arr[num_elem-i-1];
	}
	return ans;
}

int get_num_dig(int num) {
	int tmp = num;
	int ans = 0;
	while(tmp!=0) {
		tmp /= 10;
		ans ++;
	}
	return ans;
}

int solve(int num) {
	// cout << "solve called on " << num << endl;
	if(num/10 == 0) return 0;
	int ans = -inf;
	int num_dig = get_num_dig(num);
	int pow_10 = 10;
	for(int i=0; i<(num_dig-1); i++) {
		ans = max(ans, 1+solve((num/(pow_10))*(num%pow_10)));
		pow_10 *= 10;
	}
	return ans;
}

int main(int argc, char ** argv) {
	int t;
	cin >> t;
	while(t--) {
		int n = 5;
		// int a[n];
		// for(int i=0; i<5; i++) cin >> a[i];
		// int num = get_num(a, 5);
		int num;
		cin >> num;
		int ans = solve(num);
		cout << ans << endl;
	}
	return 0;
}
