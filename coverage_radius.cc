#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int> & house, int rad, int k) {
	int cov_uptil = 0;
	for(int i=0; i<house.size(); i++) {
		if(house[i] > cov_uptil) {
			k --;
			cov_uptil = house[i] + 2*rad;
		}
	}
	if(k < 0) return false;
	else return true;
}

int bin_search(vector<int> & house, int beg, int end, int k) {
	if(beg == end) return beg+1;
	else if(beg+1 == end) {
		return end;
	}
	int mid = (beg+end)/2;
	if(possible(house, mid, k)) {
		return bin_search(house, beg, mid, k);
	} else {
		return bin_search(house, mid, end, k);
	}
}

int main(int argc, char ** argv) {
	int n, k;
	cin >> n >> k;
	vector<int> house(n,0);
	for(int i=0; i<n; i++) {
		cin >> house[i];
	}
	/*
	for(int i=0; i<=((house[n-1]-house[0])/2+1); i++) {
		cout << i << ": " << possible(house, i, k) << endl;;
	}
	*/
	sort(house.begin(), house.end());
	cout << bin_search(house, 0, (house[n-1]-house[0])/2 + 1, k) << endl;
	return 0;
}
