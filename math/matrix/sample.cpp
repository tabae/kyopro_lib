#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

namespace mat {
 
    template <class T> using matrix = vector<vector<T>>;

    template <class T> 
    matrix<T> E(int n) {
        matrix<T> res(n, vector<T>(n, 0));
        rep(i, 0, n) res[i][i] = 1;
        return res;
    }

    template <class T> 
    matrix<T> matMul(matrix<T> a, matrix<T> b) {
        assert(a.size() && b.size());
        assert(a.size() == b[0].size() && a[0].size() == b.size());
        matrix<T> res(a.size(), vector<T>(b.size(), 0));
        rep(i, 0, a.size()) {
            rep(j, 0, b.size()) {
                rep(k, 0, b.size()) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
 
    template <class T> 
    vector<T> vecMul(matrix<T> a, vector<T> b) {
        assert(a.size() && b.size());
        assert(a[0].size() == b.size());
        vector<T> res(b.size(), 0);
        rep(i, 0, a.size()) {
            rep(j, 0, b.size()) {
                res[i] += a[i][j] * b[j];
            }
        }
        return res;
    }

    template <class T> 
    matrix<T> matPow(matrix<T> a, ll p) {
        assert(a.size() && a.size() == a[0].size());
        matrix<T> res(a.size(), vector<T>(a.size(), 0));
        rep(i, 0, a.size()) res[i][i] = 1;
        while(p) {
            if(p & 1) res = matMul(res, a);
            a = matMul(a, a);
            p /= 2;
        }
        return res;
    }
 
}

using namespace mat;

void solve() {
    ll n;
    cin >> n;
    if(n <= 1) cout << 1 << endl;
    else {
        matrix<ll> a = {{1,1}, {1,0}};    
        auto p = matPow(a, n-1);
        auto res = vecMul(p, {1,1});
        cout << res[0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
