#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

struct matrix {
    int n;
    vector<vector<long long int>> elems;
};

class MatrixExponentiator {
    private:
    matrix zero(int size) {
	matrix zer;
	zer.n = size;
	zer.elems.resize(size);
	for (int i = 0; i < size; i++) {
	    zer.elems[i].resize(size, 0);
	}
	return zer;
    }

    matrix identity(int size) {
	matrix id;
	id.n = size;
	id.elems.resize(size);
	for (int i = 0; i < size; i++) {
	    id.elems[i].resize(size, 0);
	    id.elems[i][i] = 1;
	}
	return id;
    }

    matrix mat_mul(const matrix& a, const matrix& b) {
	int size = a.n;
	matrix ans = zero(size);
	for (int i = 0; i < size; i++) {
	    for (int j = 0; j < size; j++) {
		for (int k = 0; k < size; k++) {
		    ans.elems[i][j] += a.elems[i][k]*b.elems[k][j];
		}
	    }
	}
	return ans;
    }


    public:
    matrix exp_bin(const matrix& a, int pow) {
	if (pow == 0) return identity(a.n);

	matrix tmp = exp_bin(a, pow/2);
	return (pow % 2) ? mat_mul(mat_mul(tmp, tmp), a) : mat_mul(tmp, tmp);
    }

    matrix exp_lin(const matrix& a, int pow) {
	matrix ans = identity(a.n);

	for (int i = 0; i < pow; i++) {
	    ans = mat_mul(a, ans);
	}

	return ans;
    }

    matrix exp(const matrix& a, int pow) {
	return exp_bin(a, pow);
    }
};

nanoseconds get_current_timestamp() {
    return duration_cast<nanoseconds>( system_clock::now().time_since_epoch() );
}

int main() {
    matrix mat = {
	2,
	{{0, 1}, {1, 1}}
    };
    MatrixExponentiator me;

    nanoseconds start_bin_exp = get_current_timestamp();
    matrix bin_exp_ans = me.exp(mat, 80);
    nanoseconds end_bin_exp = get_current_timestamp();

    for (int i = 0; i < bin_exp_ans.n; i++) {
	for (int j = 0; j < bin_exp_ans.n; j++) {
	    cout << bin_exp_ans.elems[i][j] << "\t";
	}
	cout << endl;
    }
    cout << "Time taken (ns): " << end_bin_exp.count() - start_bin_exp.count() << endl;

    nanoseconds start_lin_exp = get_current_timestamp();
    matrix lin_exp_ans = me.exp_lin(mat, 80);
    nanoseconds end_lin_exp = get_current_timestamp();

    for (int i = 0; i < lin_exp_ans.n; i++) {
	for (int j = 0; j < lin_exp_ans.n; j++) {
	    cout << lin_exp_ans.elems[i][j] << "\t";
	}
	cout << endl;
    }
    cout << "Time taken (ns): " << end_lin_exp.count() - start_lin_exp.count() << endl;
    return 0;
}


