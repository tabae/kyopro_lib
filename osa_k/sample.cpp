#include <bits/stdc++.h>
using namespace std;

/* --------- ここから --------- */
typedef struct fast_prime_factorization {
    using ll = long long;

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
        reverse(res.begin(), res.end());
        return res;
    }   
} osa_k;
/* --------- ここまで --------- */

#define MAX_a 1000010

int main() {

    // 宣言すると，コンストラクタが前処理を行う
    // MAX_a := max(a) 
    osa_k p(MAX_a); 

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {

        // a[i]を素因数分解
        auto v = p.factorize(a[i]);

        // 素因数分解結果を表示
        cout << a[i] << " = ";
        int len = v.size();
        for(int j = 0; j < len; j++) {
            cout << v[j].first << "^" << v[j].second << (j == len-1 ? "\n" : " + ");
        }
    }

    return 0;
}