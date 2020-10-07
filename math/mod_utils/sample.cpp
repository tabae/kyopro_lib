#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

/*----------------ここから---------------------*/
#include <atcoder/modint>
// parameters
using mint = atcoder::modint1000000007;
#define MOD_UTILS_NMAX 1000100

struct mod_utils {
    // data
    std::vector<mint> _fac, _inv;
    // construct & initialize
    mod_utils() { 
        _fac.resize(MOD_UTILS_NMAX);
        _inv.resize(MOD_UTILS_NMAX);
        _fac[0] = 1; _fac[1] = 1;
        _inv[0] = 1; _inv[1] = 1;
        for(int i = 2; i < MOD_UTILS_NMAX; i++) {
            _fac[i] = _fac[i-1] * mint(i);
            _inv[i] = _inv[i-1] * mint(i).inv();
        }
    }
} _mod_utils;

// functions
mint fac(int i) { return _mod_utils._fac[i]; }
mint inv_fac(int i) { return _mod_utils._inv[i]; }
mint nck(int n, int k) { 
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    if(k == 0 || k == n) return 1;
    return _mod_utils._fac[n] * _mod_utils._inv[k] * _mod_utils._inv[n-k];
}
/*----------------ここまで---------------------*/

vector<pair<ll,ll>> prime_factorize(ll N){
    vector<pair<ll,ll>> ret;
    for(ll a = 2; a * a <= N; a++){
        if(N % a != 0) continue;
        ll ex = 0;
        while(N % a == 0){
            ex++;
            N /= a;
        }
        ret.push_back({a, ex});
    }
    if(N != 1) ret.push_back({N, 1});
    return ret;
}

int main() {
    ll n, m;
    cin >> n >> m;
    auto v = prime_factorize(m);
    mint ans = 1;
    for(auto e : v) ans *= nck(e.second + n - 1, n - 1); 
    cout << ans.val() << "\n";
    return 0;
}