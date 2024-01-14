/**
 * Difficulty: Easy
 * Status: AC
 * Time: 9 min 9 sec
 */
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n1, n2, n3, tmp;
	cin >> n1 >> n2 >> n3;
	map<int, int> cnt;
	for (int i = 0; i < n1; i++) {
		cin >> tmp;
		cnt[tmp]++;
	}
	for (int i = 0; i < n2; i++) {
		cin >> tmp;
		cnt[tmp]++;
	}
	for (int i = 0; i < n3; i++) {
		cin >> tmp;
		cnt[tmp]++;
	}
	
	vector<int> vlist;
	for (map<int, int>::iterator iter = cnt.begin(); iter != cnt.end(); iter++) {
		if (iter->second > 1) vlist.push_back(iter->first);
	}
	
	sort(vlist.begin(), vlist.end());

	cout << vlist.size() << endl;
	for (int i = 0; i<vlist.size(); i++) cout << vlist[i] << endl;
	return 0;
}
