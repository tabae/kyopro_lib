#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

namespace lca {
    /* Reference: https://algo-logic.info/lca/ */

    using _ll = long long;
    typedef _ll edge;

    typedef struct lca {
        std::vector<std::vector<_ll>> parent;
        std::vector<_ll> dist;

        void dfs(std::vector<std::vector<edge>> &G, _ll cur, _ll par, _ll d) {
            dist[cur] = d;
            parent[0][cur] = par;
            for(auto e : G[cur]) if(e != par) dfs(G, e, cur, d+1);
        }

        lca(std::vector<std::vector<edge>> &G, _ll root = 0) {
            _ll n = G.size();
            _ll k = 1;
            while((1LL<<k) < n) k++;
            parent.resize(k+1, std::vector<_ll>(n, -1));
            dist.resize(n, -1);
            dfs(G, root, -1, 0);
            for(_ll i = 0; i < k; i++) {
                for(_ll j = 0; j < n; j++) {
                    if(parent[i][j] == -1) parent[i+1][j] = -1;
                    else parent[i+1][j] = parent[i][parent[i][j]];
                }
            }
        }

        _ll get_lca(_ll u, _ll v) {
            if(dist[u] < dist[v]) std::swap(u, v);
            _ll sz = parent.size();
            for(_ll i = 0; i < sz; i++) {
                _ll d = dist[u] - dist[v];
                if((d >> i) & 1LL) u = parent[i][u];
            }
            if(u == v) return u;
            for(_ll i = sz-1; i >= 0; i--) {
                if(parent[i][u] != parent[i][v]) {
                    u = parent[i][u];
                    v = parent[i][v];
                }
            }
            return parent[0][u];
        }

        _ll get_dist(_ll u, _ll v) {
            return dist[u] + dist[v] - 2 * dist[get_lca(u, v)];
        }

        /* If there is the node "a" on the path from u to v */
        bool is_on_path(_ll u, _ll v, _ll a) {
            return (get_dist(u, a) + get_dist(a, v) == get_dist(u, v));
        }
    } lca;
}

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> G(n);
    rep(i, 0, n-1) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    lca::lca t(G);
    ll q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        cout << t.get_dist(a, b) + 1 << endl;
    }
    return 0;
}