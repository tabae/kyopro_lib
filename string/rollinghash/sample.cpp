#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <set>



struct rollinghash {
    using u64 = unsigned long long;
    using u128 = __uint128_t;
    static const u64 mod = (1LL<<61) - 1;
    std::vector<u64> hash, p;
    // ref: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
    inline u64 mul(u64 a, u64 b) {
        const u128 t = (u128) a * b;
        const u128 u = (t >> 61) + (t & mod);
        return (u >= mod ? u - mod : u);
    };
    rollinghash(std::string s) {
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());
        const u64 base = engine() % 326 + 2;
        const int n = s.size();
        hash.resize(n+1, 0);
        p.resize(n+1, 1);
        for(int i = 0; i < n; i++) p[i+1] = mul(p[i], base);
        for(int i = 0; i < n; i++) hash[i+1] = (mul(hash[i], base) + (s[i]-'a'+1)) % mod;
    }; 
    // [l:r)
    long long get(int l, int r) {
        return (hash[r] - mul(hash[l], p[r-l]) + mod) % mod;
    }
};

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    rollinghash z(s);
    int l = 0, r = n + 1;
    while(r - l > 1) {
        int m = l + (r - l) / 2;
        std::set<long long> st;
        bool ok = false;
        for(int i = 0; i + m <= n; i++) {
            if(i-m >= 0) st.insert(z.get(i-m, i));
            if(st.count(z.get(i, i+m))) ok = true;
        }
        if(ok) l = m;
        else r = m;
    }
    std::cout << l << std::endl;
}