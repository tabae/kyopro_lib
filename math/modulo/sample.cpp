#include <iostream>
#include <vector>

#include <atcoder/modint>
using mint = atcoder::modint1000000007;

namespace modulo {

    constexpr int max_size = 2020202; // 2 * 10^6

    struct fact_table {
    public:
        fact_table() {
            fac.resize(max_size);
            ifac.resize(max_size);
            fac[0] = 1;
            fac[1] = 1;
            ifac[0] = 1;
            ifac[1] = 1;
            for(int i = 2; i < max_size; i++) {
                fac[i] = fac[i-1] * i;
                ifac[i] = ifac[i-1] / i;
            }
        }
        mint factor(int n) {
            assert(n < max_size);
            return fac[n];
        }
        mint ifactor(int n) {
            assert(n < max_size);
            return ifac[n];
        }
        mint comb(int n, int k) {
            if(n < k || n < 0 || k < 0) return 0;
            if(k == 0 || k == n) return 1;
            return fac[n] * ifac[k] * ifac[n-k];
        }
    private:
        std::vector<mint> fac, ifac;
    } table;

    template<class T>
    mint fac(T n) {
        return table.factor(n);
    }
    template<class T>
    mint ifac(T n) {
        return table.ifactor(n);
    }
    template<class T>
    mint comb(T n, T k) {
        return table.comb(n, k);
    }

}

int main() {
    int n, k;
    std::cin >> n >> k;
    if(n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    if(k == 1) {
        std::cout << n << std::endl;
        return 0;
    }
    mint ans = 0;
    for(int i = 0; i < n; i++) {
        ans += modulo::comb(k - 2 + i, k - 2) * (n - i);
    }
    std::cout << ans.val() << std::endl;
    return 0;
}