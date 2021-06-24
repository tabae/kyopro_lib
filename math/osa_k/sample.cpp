#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

namespace osa_k {

    using ll = long long;
    constexpr int max_size = 2020202; // 2 * 10^6
    
    struct min_factor_table {
    public:
        min_factor_table() {
            min_factor.resize(max_size, 1);
            for(int i = 2; i < max_size; i++) {
                if(min_factor[i] != 1) continue;
                for(int j = i; j < max_size; j += i) {
                    if(min_factor[j] != 1) continue;
                    min_factor[j] = i;
                }
            }
        }
        std::vector<std::pair<int, int>> prime_factorize(int n) {
            assert(n < max_size);
            std::vector<std::pair<int, int>> res;
            while(n != 1) {
                int fact = min_factor[n];
                int count = 0;
                while(n % fact == 0) {
                    n /= fact;
                    count++;
                }
                res.emplace_back(fact, count);
            }
            sort(res.begin(), res.end());
            return res;
        }
    private:
        std::vector<int> min_factor;
    } table;

    template<class T = int>
    std::vector<std::pair<int, int>> prime_factorize(T n) {
        return table.prime_factorize(n);
    } 
    
}

#include <numeric>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    bool pairwise = true, setwise;
    std::vector<bool> seen(2020202, false);
    for(auto e : a) {
        auto v = osa_k::prime_factorize(e);
        for(auto [f, s] : v) {
            if(seen[f]) {
                pairwise = false;
                break;
            }
            seen[f] = true;
        }
        if(!pairwise) break;
    }
    int g = 0;
    for(auto e : a) g = std::gcd(g, e);
    setwise = g == 1;
    if(pairwise) std::cout << "pairwise coprime" << std::endl;
    else if(setwise) std::cout << "setwise coprime" << std::endl;
    else std::cout  << "not coprime" << std::endl;
    return 0;
}