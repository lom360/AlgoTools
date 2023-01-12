#include <iostream>


const int MAXN = 2;
struct matrix {
    long long mat[MAXN][MAXN];
    matrix() { memset(mat, 0, sizeof mat); }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

matrix operator*(matrix a, matrix b) {
    matrix c;
    for(int i = 0 i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
	    for(int k = 0; k < MAXN; k++) {
	        c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % m;
	    }
	}
    }
    return c;
}

matrix mat_pow(matrix a, int b) {
    matrix res;
    for(int i = 0; i < MAXN; i++) res.mat[i][i] = 1;
    while(b) {
        if(b & 1) res = res * a;
	a = a * a;
	b >>= 1;
    }
    return res;
}

long long fib(int n) {
    if(n == 0) return 0;
    matrix F = {{1,1},{1,0}};
    F = mat_pow(F, n - 1);
    return F.mat[0][0];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << fib(n) % m << endl;
    return 0;
}
