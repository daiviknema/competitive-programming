#include <bits/stdc++.h>

#define DEBUG false
#define MOD 1000000007

using namespace std;

// TODO:templatize
struct matrix {
    int size;
    vector<vector<long long>> elems;

    public:
    matrix(int size) : size(size) {
	elems.resize(size);
	for (int i = 0; i < size; i++) {
	    elems[i].resize(size);
	    for (int j = 0; j < size; j++) {
		elems[i][j] = 0ll;
	    }
	}
    }
};

class MatrixExponentiator {
    private:
    matrix mat_mul(const matrix& m1, const matrix& m2) {
	assert(m1.size == m2.size);
	int size = m1.size;

	matrix res(size);
	for (int i = 0; i < size; i++) {
	    for (int j = 0; j < size; j++) {
		res.elems[i][j] = 0;
		for (int k = 0; k < size; k++) {
		    res.elems[i][j] += (m1.elems[i][k]%MOD)*(m2.elems[k][j]%MOD);
		    res.elems[i][j] %= MOD;
		}
	    }
	}
	return res;
    }

    matrix identity(int size) {
	matrix m(size);
	for (int i = 0; i < size; i++) {
	    m.elems[i][i] = 1ll;
	}
	return m;
    }

    public:
    matrix exp_bin(const matrix& mat, int pow) {
	int size = mat.size;

	// assertions for valid input
	assert(size > 0);
	assert(size == mat.elems.size());
	for (int i = 0; i < size; i++) {
	    assert(size == mat.elems.size());
	}

	if (pow == 0) return identity(size);
	
	matrix half = exp_bin(mat, pow/2);

	// TODO: check if RVO will happen
	return (pow%2) ? mat_mul(mat_mul(half, half), mat) : mat_mul(half, half);

    }

    matrix exp(const matrix& mat, int pow) {
	return exp_bin(mat, pow);
    }

    // TODO: implement
    // matrix exp_iter(const matrix& mat, int pow) {
    // }
};

int main() {
    long long int n, m, k;
    cin >> n >> m >> k;
    matrix adj_list(m);
    for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	    adj_list.elems[i][j] = 1;
	}
    }

    for (int i = 0; i < k; i++) {
	string forbidden_nucleotide_seq;
	cin >> forbidden_nucleotide_seq;
	assert(forbidden_nucleotide_seq.length() == 2);
	assert((forbidden_nucleotide_seq[0] <= 'z' && forbidden_nucleotide_seq[0] >= 'a') || (forbidden_nucleotide_seq[0] <= 'Z' && forbidden_nucleotide_seq[0] >= 'A'));
	assert((forbidden_nucleotide_seq[1] <= 'z' && forbidden_nucleotide_seq[1] >= 'a') || (forbidden_nucleotide_seq[1] <= 'Z' && forbidden_nucleotide_seq[1] >= 'A'));

	
	int idx1 = 0;
	int idx2 = 0;
	if((forbidden_nucleotide_seq[0] <= 'z' && forbidden_nucleotide_seq[0] >= 'a')) idx1 = forbidden_nucleotide_seq[0] - 'a';
	else idx1 = forbidden_nucleotide_seq[0] - 'A';
	if((forbidden_nucleotide_seq[1] <= 'z' && forbidden_nucleotide_seq[1] >= 'a')) idx2 = forbidden_nucleotide_seq[1] - 'a';
	else idx2 = forbidden_nucleotide_seq[1] - 'A';
	adj_list.elems[idx1][idx2] = 0;
    }

#if DEBUG
    for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	    cout << adj_list.elems[i][j] << " ";
	}
	cout << endl;
    }
#endif
    MatrixExponentiator me;
    matrix ans = me.exp(adj_list, n-1);
    long long int sum = 0;
    for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	    sum += ans.elems[i][j];
	    sum %= MOD;
	}
    }
#if DEBUG
    for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	    cout << ans.elems[i][j] << " ";
	}
	cout << endl;
    }
#endif
    cout << sum << endl;

    return 0;
}
