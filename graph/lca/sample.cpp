#include <iostream>
#include <vector>

// Reference: https://algo-logic.info/lca/
template<class T = int>
struct lca {
public: 
    void dfs(std::vector<std::vector<T>> &G, int cur, int par, int d) {
        dist[cur] = d;
        parent[0][cur] = par;
        for(auto e : G[cur]) if(e != par) dfs(G, e, cur, d+1);
    }
    lca(std::vector<std::vector<T>> &G, int root = 0) {
        int n = G.size();
        int k = 1;
        while((1LL<<k) < n) k++;
        parent.resize(k+1, std::vector<int>(n, -1));
        dist.resize(n, -1);
        dfs(G, root, -1, 0);
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < n; j++) {
                if(parent[i][j] == -1) parent[i+1][j] = -1;
                else parent[i+1][j] = parent[i][parent[i][j]];
            }
        }
    }
    int get_lca(int u, int v) {
        if(dist[u] < dist[v]) std::swap(u, v);
        int sz = parent.size();
        for(int i = 0; i < sz; i++) {
            int d = dist[u] - dist[v];
            if((d >> i) & 1LL) u = parent[i][u];
        }
        if(u == v) return u;
        for(int i = sz-1; i >= 0; i--) {
            if(parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
    int get_dist(int u, int v) {
        return dist[u] + dist[v] - 2 * dist[get_lca(u, v)];
    }
    /* If there is the node "a" on the path from u to v */
    bool is_on_path(int u, int v, int a) {
        return (get_dist(u, a) + get_dist(a, v) == get_dist(u, v));
    }

private:
    std::vector<std::vector<int>> parent;
    std::vector<int> dist;
};

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n-1);
    std::vector<std::vector<int>> G(n);
    for(int i = 1; i < n; i++) std::cin >> p[i];
    for(int i = 1; i < n; i++) G[p[i]].push_back(i);
    lca t(G);
    for(int i = 0; i < q; i++) {
        int u, v;
        std::cin >> u >> v;
        std::cout << t.get_lca(u, v) << "\n";
    }
    return 0;
}