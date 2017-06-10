#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll inf = 1000000000+9;

typedef enum {
	red,
	orange,
	yellow,
	green,
	blue
} color;

typedef enum {
	plastic,
	glass,
	aluminium,
	steel,
	newspaper
} waste;

int main(int argc, char ** argv) {
	bool fin = false;
	ll city_num = 0;
	vvi col(103, vi(5,-1));
	while(true) {
		while(true) {
			string cheese;
			cin >> cheese;
			if(cheese == "#") {
				fin = true;
				break;
			}
			for(ll i=0; i<cheese.length(); i++)
				if(cheese[i] == ',') cheese[i] = ' ';
			istringstream cinn(cheese);
			string token;
			bool br = false;
			while(cinn >> token) {
				if(token[0] == 'e') {
					br = true;
					break;
				}
				waste w;
				color c;
				switch(token[0]) {
					case 'r':
						c = red;
						break;
					case 'o':
						c = orange;
						break;
					case 'y':
						c = yellow;
						break;
					case 'g':
						c = green;
						break;
					case 'b':
						c = blue;
						break;
				}
				switch(token[2]) {
					case 'P':
						w = plastic;
						break;
					case 'G':
						w = glass;
						break;
					case 'A':
						w = aluminium;
						break;
					case 'S':
						w = steel;
						break;
					case 'N':
						w = newspaper;
						break;
				}
				col[city_num][(ll)w] = (ll)c;
			}
			if(br) break;
			city_num++;
		}
		if(fin) break;
		/*
		for(ll i=0; i<city_num; i++) {
			cout << i << ": ";
			for(ll j=0; j<5; j++) {
				cout << col[i][j] << " ";
			}
			cout << endl;
		}
		*/
		ll min_dif = inf;
		ll min_dif_city  = -1;
		for(ll i=0; i<city_num; i++) {
			ll dif = 0;
			for(ll j=0; j<city_num; j++) {
				if(j != i) {
					for(ll k=0; k<5; k++) {
						if(col[i][k] != col[j][k]) dif++;
					}
				}
			}
			if(dif < min_dif) {
				min_dif = dif;
				min_dif_city = i;
			}
		}
		cout << min_dif_city+1 << endl;
		for(ll i=0; i<103; i++) col[i].clear();
		col.clear();
		col.resize(103, vi(5,-1));
		city_num = 0;
	}
	
	return 0;
}
