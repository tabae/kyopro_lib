#include <bits/stdc++.h>
using namespace std;

/* --------- ここから --------- */
using _ll = long long;

#define PRIME_FACTORIZE_MAX 2000010
_ll primes[PRIME_FACTORIZE_MAX];

void pre_osa_k() {
    for(_ll i = 0; i < PRIME_FACTORIZE_MAX; i++) {
        primes[i] = 1;
    }
    for(_ll i = 2; i < PRIME_FACTORIZE_MAX; i++) {
        if(primes[i] != 1) continue;
        for(_ll j = i; j <= PRIME_FACTORIZE_MAX; j += i) {
            primes[j] = i;
        }
    }
}

vector<pair<_ll,_ll>> factorize(_ll n){
    vector<pair<_ll,_ll>> res;
    while(n != 1) {
        _ll cur = primes[n];
        _ll cnt = 0;
        while(n % cur == 0) {
            n /= cur;
            cnt++;
        }
        res.push_back({cur, cnt});
    }
    reverse(res.begin(), res.end());
    return res;
}
/* --------- ここまで --------- */

int main() {

    // 前処理
    pre_osa_k();

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {

        // a[i]を素因数分解
        auto v = factorize(a[i]);

        // 素因数分解結果を表示
        cout << a[i] << " = ";
        int len = v.size();
        for(int j = 0; j < len; j++) {
            cout << v[j].first << "^" << v[j].second << (j == len-1 ? "\n" : " + ");
        }
    }

    return 0;
}