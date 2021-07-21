#include <vector>
#include <algorithm>
#include <iostream>

namespace centroid {
    
    using ll = long long;
    
    ll dfs(std::vector<std::vector<ll>>& G, std::vector<ll>& max_subtree, ll cur, ll par, ll n) {
        ll mx = 0, sum = 0;
        for(auto g : G[cur]) {
            if(g == par) continue;
            ll tmp = dfs(G, max_subtree, g, cur, n);
            sum += tmp;
            mx = std::max(mx, tmp);
        }
        mx = std::max(mx, n - sum - 1);
        max_subtree[cur] = mx;
        return sum + 1;
    }

    std::vector<ll> find(std::vector<std::vector<ll>>& G) {
        ll n = G.size();
        std::vector<ll> max_subtree(n, 0);
        dfs(G, max_subtree, 0, -1, n);
        std::vector<ll> res;
        ll mn = *min_element(max_subtree.begin(), max_subtree.end());
        for(ll i = 0; i < n; i++) if(max_subtree[i] == mn) res.push_back(i);
        return res;
    }

}


using ll = long long;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<std::vector<ll>> G(n);
    for(ll i = 0; i < n-1; i++) {
        ll u, v;
        std::cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto v = centroid::find(G);
    if(v.size() == 1) {
        for(ll i = 0; i < 2; i++) std::cout << 1 << " " << G[0][0]+1 << std::endl;
        return;
    }
    ll cut;
    for(auto g : G[v[1]]) {
        if(g == v[0]) continue;
        cut = g;
        break;
    }
    std::cout << v[1]+1 << " " << cut+1 << std::endl;
    std::cout << v[0]+1 << " " << cut+1 << std::endl; 
}

int main() {
    ll t;
    std::cin >> t;
    while(t--) solve();
    return 0;
}