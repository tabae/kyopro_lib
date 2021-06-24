#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

namespace mm {
 
    template <class T> using matrix = std::vector<std::vector<T>>;

    template <class T> 
    matrix<T> E(int n) {
        matrix<T> res(n, std::vector<T>(n, 0));
        for(int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }

    template <class T> 
    matrix<T> matMul(matrix<T> a, matrix<T> b) {
        assert(a.size() && b.size());
        assert(a[0].size() == b.size());
        matrix<T> res(a.size(), std::vector<T>(b[0].size(), 0));
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b[0].size(); j++) {
                for(int k = 0; k < b.size(); k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
 
    template <class T> 
    std::vector<T> vecMul(matrix<T> a, std::vector<T> b) {
        assert(a.size() && b.size());
        assert(a[0].size() == b.size());
        std::vector<T> res(b.size(), 0);
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                res[i] += a[i][j] * b[j];
            }
        }
        return res;
    }

    template <class T> 
    matrix<T> matPow(matrix<T> a, long long p) {
        assert(a.size() && a.size() == a[0].size());
        matrix<T> res(a.size(), std::vector<T>(a.size(), 0));
        for(int i = 0; i < a.size(); i++) res[i][i] = 1;
        while(p) {
            if(p & 1) res = matMul(res, a);
            a = matMul(a, a);
            p /= 2;
        }
        return res;
    }
 
}

using namespace mm;

#include <atcoder/modint>
using mint = atcoder::modint998244353;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    matrix<mint> a(n, std::vector<mint>(m));
    matrix<mint> b(m, std::vector<mint>(k));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        int val; 
        std::cin >> val;
        a[i][j] = val;
    }
    for(int i = 0; i < m; i++) for(int j = 0; j < k; j++) {
        int val;
        std::cin >> val;
        b[i][j] = val;
    }
    auto c = matMul(a, b);
    for(int i = 0; i < n; i++) for(int j = 0; j < k; j++) {
        std::cout << c[i][j].val() << (j == k-1 ? "\n" : " ");
    }
    return 0;
}
