// https://codeforces.com/contest/612/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_frags;
    cin >> num_frags;

    unordered_map<int, int> frag_to_sector;

    // here i is sector number
    for (int i = 1; i <= num_frags; i++) {
	int sector_to_frag_i;
	cin >> sector_to_frag_i;
	frag_to_sector[sector_to_frag_i] = i;
    }

    long long int time = 0;

    // here i is fragment number
    for (int i = 1; i < num_frags; i++) {
	time += abs(frag_to_sector[i+1] - frag_to_sector[i]);
    }

    cout << time << endl;


    return 0;
}
