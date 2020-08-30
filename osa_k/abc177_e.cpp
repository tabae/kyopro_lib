#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

typedef struct fast_prime_factorization {

    ll PRIME_FACTORIZE_MAX;
    vector<ll> primes;

    void erathos() {
        for(ll i = 2; i <= PRIME_FACTORIZE_MAX; i++) {
            if(primes[i] != 1) continue;
            for(ll j = i; j <= PRIME_FACTORIZE_MAX; j += i) {
                primes[j] = i;
            }
        }
    }

    fast_prime_factorization(ll _NMAX) : PRIME_FACTORIZE_MAX(_NMAX) {
        primes.resize(PRIME_FACTORIZE_MAX, 1);
        erathos();
    }

    vector<pair<ll,ll>> factorize(ll n){
        vector<pair<ll,ll>> res;
        while(n != 1) {
            ll cur = primes[n];
            ll cnt = 0;
            while(n % cur == 0) {
                n /= cur;
                cnt++;
            }
            res.push_back({cur, cnt});
        }
        return res;
    }
    
} osa_k;


ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = a / gcd(a,b) * b;
    return ret;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    bool pair_wise = true;
    set<ll> seen;
    osa_k p(1000010);
    rep(i, 0, n) {
        auto v = p.factorize(a[i]);
        for(auto e : v) {
            if(seen.count(e.first)) {
                pair_wise = false;
                break;
            }
            seen.insert(e.first);
        }
        if(!pair_wise) break;
    }
    if(pair_wise) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    ll g = a[0];
    rep(i, 0, n) g = gcd(g, a[i]);
    if(g == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    return 0;
}
