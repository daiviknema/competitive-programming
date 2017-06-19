#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_NODES = 100;

void mult(long double* res, long double tm[][MAX_NODES], int num_nodes) {
	long double ans[MAX_NODES];
	memset(ans, 0, sizeof ans);
	for(int i=0; i<num_nodes; i++) {
		for(int j=0; j<num_nodes; j++) {
			ans[i] += tm[j][i]*res[j];
		}
	}
	for(int i=0; i<num_nodes; i++)
		res[i] = ans[i];
}

int main(int argc, char ** argv) {
	int num_nodes;
	cin >> num_nodes;
	int num_edges;
	cin >> num_edges;
	long double tm[MAX_NODES][MAX_NODES];
	/*
	long double ** tm;
	tm = (long double**)malloc(sizeof(long double*)*MAX_NODES);
	for(int i=0; i<MAX_NODES; i++)
		tm[i] = (long double*)malloc(MAX_NODES*sizeof(long double));
	for(int i=0; i<MAX_NODES; i++)
		for(int j=0; j<MAX_NODES; j++) tm[i][j] = 0.0;
	*/
	int from[MAX_NODES];
	int to[MAX_NODES];
	long double transitions[MAX_NODES];
	for(int i=0; i<num_edges; i++) {
		cin >> from[i];
		from[i] --;
	}
	for(int i=0; i<num_edges; i++) {
		cin >> to[i];
		to[i] -- ;
	}
	for(int i=0; i<num_edges; i++) {
		cin >> transitions[i];
	}
	for(int i=0; i<num_edges; i++) {
		tm[from[i]][to[i]] = transitions[i];
	}
	int num_time_steps;
	while( cin >> num_time_steps ) {
		int ans = -1;
		if(num_time_steps == 0) {
			ans = 0;
			cout << ans+1 << " 1" << endl;
		} else {
			long double res[MAX_NODES];
			for(int i=0; i<num_nodes; i++)
				res[i] = tm[0][i];
			for(int i=0; i<(num_time_steps-1); i++) {
				mult(res, tm, num_nodes);
			}
			int arg_max = -1;
			long double max = -1.5;
			for(int i=0; i<num_nodes; i++) {
				if(res[i] > max) {
					max = res[i];
					arg_max = i;
				}
			}
			cout << arg_max+1 << " " << max << endl;
		}
	}

	return 0;
}
