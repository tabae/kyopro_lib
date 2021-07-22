#include <iostream>
#include <vector>

namespace tree_diameter {
    
    using ll = long long;
    using pl = std::pair<ll, ll>;

    pl dfs(const std::vector<std::vector<pl>>& G, ll cur, ll par) {
        pl res = {0, cur};
        for(auto [to, cost] : G[cur]) {
            if(to == par) continue;
            auto tmp = dfs(G, to, cur);
            if(res.first < tmp.first + cost) {
                res.first = tmp.first + cost;
                res.second = tmp.second;
            }
        }
        return res;
    }

    ll len(const std::vector<std::vector<pl>>& G) {
        auto [a, x] = dfs(G, 0, -1);
        auto [b, y] = dfs(G, x, -1);
        return b;
    }

    ll len(const std::vector<std::vector<ll>>& G) {
        std::vector<std::vector<pl>> dummyG(G.size());
        for(int i = 0; i < G.size(); i++) {
            for(const auto& e: G[i]) dummyG[i].push_back({e, 1});
        }
        return len(dummyG);
    }

    std::vector<ll> path(const std::vector<std::vector<pl>>& G) {
        auto s = dfs(G, 0, -1).second;
        auto t = dfs(G, s, -1).second;
        std::vector<ll> res;
        auto dfs = [&](auto dfs, ll cur, ll par) -> bool {
            bool f = false;
            res.push_back(cur);
            if(cur == t) return true;
            for(auto [to, cost] : G[cur]) {
                if(to == par) continue;
                if(dfs(dfs, to, cur)) {
                    f = true;
                    break;
                }
            }
            if(!f) res.pop_back();
            return f;
        };
        dfs(dfs, s, -1);
        return res;
    }

    std::vector<ll> path(const std::vector<std::vector<ll>>& G) {
        std::vector<std::vector<pl>> dummyG(G.size());
        for(int i = 0; i < G.size(); i++) {
            for(const auto& e: G[i]) dummyG[i].push_back({e, 1});
        }
        return path(dummyG);
    }

}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<long long, long long>>> G(n);
    for(int i = 0; i < n - 1; i++) {
        long long u, v, w;
        std::cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }    
    auto len = tree_diameter::len(G);
    auto v = tree_diameter::path(G);
    std::cout << len << " " << v.size() << "\n";
    for(int i = 0; i < v.size(); i++) std::cout << v[i] << (i == v.size()-1 ? "\n" : " ");
}