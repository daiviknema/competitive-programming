#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int B_SZ_MAX = 10;

typedef struct {
	int row;
	int col;
} ii;

bool is_safe(ii * queens, int r, int c) {
	for(int i=0; i<=(r-1); i++) {
		if(	
			queens[i].row == r || 
			queens[i].col == c || 
			((queens[i].row-r)%(queens[i].col-c) == 0 &&  abs(queens[i].row-r)/abs(queens[i].col - c) == 1)
		)
		{
			return false;
		}
	}
	return true;
}

ii solutions[1000][B_SZ_MAX];
int num_solutions = 0;

void save_queens(ii * queens, int board_size) {
	for(int i=0; i<board_size; i++) {
		solutions[num_solutions][i] = queens[i];
	}
	num_solutions++;
}

bool solve(ii * queens, int num_remaining, int num_placed, int board_sz) {
	// queens[num_placed]
	if(num_remaining == 0) {
		save_queens(queens, board_sz);
		// return true;
	}
	for(int i=0; i<board_sz; i++) {
		if(is_safe(queens, num_placed, i)) {
			// cout << "row: " << num_placed << " col: " << i << " is safe " << endl;
			queens[num_placed].row = num_placed;
			queens[num_placed].col = i;
			if(solve(queens, num_remaining-1, num_placed+1, board_sz)) {
				// return true;
			}
		}
	}
	// return false;
	return true;
}


int main(int argc, char ** argv) {
	int num_queens = 8;
	int board_sz = 8;
	ii queens[num_queens];
	memset(queens, 0, sizeof queens);
	/*
	if(solve(queens, num_queens, 0, board_sz)) {
		for(int i=0; i<num_queens; i++) {
			cout << queens[i].row << " " << queens[i].col << endl;
		}
	} else {
		cout << "Not possible" << endl;
	}
	*/
	solve(queens, num_queens, 0, board_sz);
	if(num_solutions == 0) {
		cout << "Not possible" << endl;
	} else {
		// cout << "Number of solutions: " <<num_solutions << endl;
		// getchar();
		cout << num_solutions << endl;
		for(int i=0; i<num_solutions; i++) {
			for(int j=0; j<num_queens; j++) {
				cout << solutions[i][j].row << " " << solutions[i][j].col << endl;
			}
		}
	}
	return 0;
}
