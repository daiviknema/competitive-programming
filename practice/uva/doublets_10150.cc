#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll BUF_SZ = 100;
const ll inf = 1000000000+9;

int readword(char * buffer, ll bufsz) {
	memset(buffer, 0, bufsz);
	// strcpy(buffer, "daivik");
	ll ch_ptr = 0;
	char ch;
	while((ch=getchar()) != '\n') buffer[ch_ptr++] = ch;
	buffer[ch_ptr++] = '\0';
	if(ch_ptr == 1) return -1;
	return 0;
}

bool cmpfn(const char * s1, const char * s2) {
	ll i=0;
	while(i<BUF_SZ && s1[i] == s2[i]) i++;
	if(i == BUF_SZ) return true;
	else return s1[i] < s2[i];
}

ll search(char * dict[25145], ll dict_sz, ll beg, ll end, const char * key) {
	if(beg > end) return -1;
	if(beg == end) if(strcmp(key, dict[beg]) == 0) return beg;
	else if(beg+1 == end) {
		if(!strcmp(dict[beg],key)) return beg;
		if(!strcmp(dict[end],key)) return end;
		else return -1;
	}
	ll mid = (ll)(beg+end)/2ll;
	if(!strcmp(dict[mid],key)) return mid;
	if(!cmpfn(dict[mid],key)) {
		return search(dict, dict_sz, beg, mid-1, key);
	} else {
		return search(dict, dict_sz, mid+1, end, key);
	}
}

int main(int argc, char ** argv) {
	
	char * dict[25145];
	ll dict_sz = 0;
	while(true) {
		char * buffer = (char*)malloc(sizeof(char)*BUF_SZ);
		dict[dict_sz] = (char*)malloc(sizeof(char)*BUF_SZ);
		memset(buffer, 0, BUF_SZ);
		memset(dict[dict_sz], 0, BUF_SZ);
		ll x = readword(buffer, BUF_SZ);
		if(x < 0) break;
		strcpy(dict[dict_sz++], buffer);
		// cout << dict[dict_sz-1] << endl;
	}
	map<string, ll> str_idx;
	sort(dict, dict+dict_sz, cmpfn);
	for(ll i=0; i<dict_sz; i++) {
		// cout << dict[i] << endl;
		str_idx[string(dict[i])] = i;
	}
	// char search_string[BUF_SZ] = "coasted";
	// cout << search(dict, dict_sz, 0, dict_sz-1, search_string) << endl;
	vector< vector<ll> > al(dict_sz);
	for(ll i=0; i<dict_sz; i++) {
		for(ll j=0; j<strlen(dict[i]); j++) {
			for(char ch = 'a'; ch <= 'z'; ch++) {
				char tmp[BUF_SZ];
				strcpy(tmp, dict[i]);
				tmp[j] = ch;
				if(search(dict, dict_sz, 0, dict_sz-1, tmp) != -1 && strcmp(tmp,dict[i])) {
					// add tmp to adjacency list
					al[i].push_back(str_idx[string(tmp)]);
				}
			}
		}
	}
	/*
	for(ll i=0; i<dict_sz; i++) {
		cout << i << ": ";
		for(ll j=0; j<al[i].size(); j++) {
			cout << al[i][j] << " ";
		}
		cout << endl;
	}
	*/
	// char src[BUF_SZ], dst[BUF_SZ];
	string src, dst;
	ll q_no = 0;
	while(cin >> src >> dst) {
		// cout << src << " " <<  str_idx[src] << " " << dst << " " << str_idx[dst] << endl;
		// perform bfs from str_idx[dst] and build parent graph
		// follow parents starting from src and keep printing simultaneously

		if(q_no > 0) cout << endl;
		q_no ++;
		if(src == dst) {
			cout << "No solution." << endl;
			continue;
		}
		if(search(dict, dict_sz, 0, dict_sz-1ll, src.c_str()) == -1ll) {
			cout << "No solution." << endl << endl;
			continue;
		}
		if(search(dict, dict_sz, 0, dict_sz-1ll, dst.c_str()) == -1ll) {
			cout << "No solution." << endl << endl;
			continue;
		}
		ll src_idx = str_idx[src];
		ll dst_idx = str_idx[dst];

		queue<ll> q;
		q.push(dst_idx);
		vector<ll> par(dict_sz, inf);
		vector<ll> lvl(dict_sz, inf);
		vector<bool> vis(dict_sz, false);
		par[dst_idx] = -1;
		lvl[dst_idx] = 0;
		while(!q.empty()) {
			ll curr = q.front();
			q.pop();
			vis[curr] = true;
			for(ll i=0; i<al[curr].size(); i++) {
				if(!vis[al[curr][i]]) {
					q.push(al[curr][i]);
					lvl[al[curr][i]] = min(lvl[al[curr][i]], lvl[curr]+1);
					if(lvl[al[curr][i]] == lvl[curr]+1)
						par[al[curr][i]] = curr;
				}
			}
		}
		/*
		for(ll i=0; i<dict_sz; i++)
			if(par[i] != -1 && par[i] != inf)
				cout << dict[i] << " has parent " << dict[par[i]] << endl;
		*/
		ll cur_idx = src_idx;
		vi sequence;
		while(true) {
			if(cur_idx == -1 || cur_idx == inf) break;
			sequence.push_back(cur_idx);
			cur_idx = par[cur_idx];
		}
		if(cur_idx == -1) {
			for(ll i=0; i<sequence.size(); i++) {
				cout << dict[sequence[i]] << endl;
			}

		} else {
			cout << "No solution." << endl;
		}


	}
	return 0;
}
