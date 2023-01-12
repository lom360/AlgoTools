#include <iostream>
using namespace std;

const int N = 2;

struct matrix {
    long long m[N][N];
};

matrix operator*(matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c.m[i][j] = 0;
            for (int k = 0; k < N; k++) {
                c.m[i][j] += (a.m[i][k] * b.m[k][j]);
            }
        }
    }
    return c;
}

long long fibonacci(long long n, int m) {
    if (n == 0) return 0;
    matrix A;
    A.m[0][0] = 1;
    A.m[0][1] = 1;
    A.m[1][0] = 1;
    A.m[1][1] = 0;
    matrix res = A;
    n--;
    while (n > 0) {
        if (n % 2 == 1) res = res * A;
        A = A * A;
        n /= 2;
    }
    return res.m[0][1] % m;
}

int main() {
    long long n;
    int m;
    cin >> n >> m;
    cout << fibonacci(n, m) << endl;
    return 0;
}
