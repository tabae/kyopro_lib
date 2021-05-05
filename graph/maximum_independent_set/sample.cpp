#include <iostream>
#include <vector>
#include <numeric>

// - Reference: http://kurkur.hatenablog.com/entry/2018/02/08/022629
// - 自己ループははじいてください．
// - 重複辺もはじいてください．
std::vector<int> max_independent_set(const std::vector<std::vector<int>> &G) {
    int n = G.size();
    int n1 = n/2, n2 = n-n1;
    std::vector<int> ok1(1<<n1, 1), ok2(1<<n2, 1), ok3(1<<n1, 0), dp(1<<n2, 0), rec(1<<n2);
    iota(rec.begin(), rec.end(), 0);
    for(int i = 0; i < n1; i++) for(auto u: G[i]) if(u < n1) ok1[(1<<i)|(1<<u)] = 0;
    for(int i = 0; i < (1<<n1); i++) if(!ok1[i]) for(int j = 0; j < n1; j++) ok1[i|(1<<j)] = 0;
    for(int i = n1; i < n; i++) for(auto u: G[i]) if(u >= n1) ok2[(1<<(i-n1))|(1<<(u-n1))] = 0;
    for(int i = 0; i < (1<<n2); i++) if(!ok2[i]) for(int j = 0; j < n2; j++) ok2[i|(1<<j)] = 0;
    for(int i = 0; i < (1<<n2); i++) if(ok2[i]) dp[i] = __builtin_popcount(i);
    for(int i = 0; i < (1<<n2); i++) for(int j = 0; j < n2; j++) {
        if(dp[i|(1<<j)] < dp[i]) {
            dp[i|(1<<j)] = dp[i];
            rec[i|(1<<j)] = rec[i];
        }
    }
    ok3[0] = (1<<n2) - 1;
    for(int i = 0; i < n1; i++) {
        ok3[1<<i] = (1<<n2) - 1;
        for(auto u: G[i]) if(u >= n1) ok3[1<<i] ^= (1<<(u-n1));
    }
    for(int i = 0; i < (1<<n1); i++) for(int j = 0; j < n1; j++) ok3[i|(1<<j)] = ok3[i] & ok3[1<<j];
    int count = 0, mask1 = 0, mask2 = 0;
    for(int i = 0; i < (1<<n1); i++) if(ok1[i]) {
        int tmp = __builtin_popcount(i) + dp[ok3[i]];
        if(count < tmp) {
            count = tmp;
            mask1 = i;
            mask2 = rec[ok3[i]];
        }
    }
    std::vector<int> vertices;
    for(int i = 0; i < n1; i++) if(mask1 & (1<<i)) vertices.push_back(i);
    for(int i = 0; i < n2; i++) if(mask2 & (1<<i)) vertices.push_back(i+n1);
    return vertices;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> G(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto res = max_independent_set(G);
    std::cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << (i == res.size()-1 ? "\n" : " ");
    }
}