#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

namespace kruskal {

    using ll = long long;
    using pl = std::pair<ll, ll>;
    
    struct union_find {
    public:
        union_find(int _n) : n(_n), group(_n) {
            parent.resize(n);
            nums.resize(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int root(int x) {
            if(parent[x] == x) return x;
            parent[x] = root(parent[x]);
            return parent[x];
        }
        // Merge y to x
        void merge(int x, int y) {
            int rx = root(x);
            int ry = root(y);
            if(rx != ry){
                group--;
                parent[ry] = rx;
                nums[rx] += nums[ry];
            }
        }
        bool same(int x, int y) {
            return (root(x) == root(y));
        }
        int size() {
            return group;
        }
        int size(int x) {
            return nums[root(x)];
        }
    private:
        int n, group;
        std::vector<int> parent;
        std::vector<int> nums;
    };  

    struct edge {
        ll v1, v2, cost, id;
    };

    struct mst {
    public:
        mst(int _n) : n(_n), build_cost(-1) {}
        void add_edge(int v1, int v2, int cost) {
            edges.push_back(edge{v1, v2, cost, (ll)edges.size()});
        } 
        void add_edge(int v1, int v2, int cost, int id) {
            edges.push_back(edge{v1, v2, cost, id});
        }
        ll build() {
            union_find uf(n);
            ll cost = 0;
            auto copied_edges = edges;
            sort(copied_edges.begin(), copied_edges.end(), [](const auto& l, const auto& r) {
                return l.cost < r.cost;
            });
            for(auto e : copied_edges) {
                if(uf.same(e.v1, e.v2)) continue;
                uf.merge(e.v1, e.v2);
                cost += e.cost;
                used_edges.push_back(e.id);
            }
            build_cost = cost;
            return cost;
        }
        ll get_cost() {
            if(build_cost == -1) build();
            return build_cost;
        }
        std::vector<std::vector<pl>> get_tree() {
            if(build_cost == -1) build();
            std::vector<std::vector<pl>> G(n);
            for(auto e : used_edges) {
                G[edges[e].v1].push_back({edges[e].v2, edges[e].cost});
                G[edges[e].v2].push_back({edges[e].v1, edges[e].cost});
            }
            return G;
        }
        std::vector<ll> get_used_edges() {
            if(build_cost == -1) build();
            return used_edges;
        }
    private:
        int n; // # of verticies
        ll build_cost;
        std::vector<edge> edges;
        std::vector<ll> used_edges;
    };

    mst make_mst(const std::vector<std::vector<pl>>& G) {
        int n = G.size();
        mst t(n);
        for(int i = 0; i < n; i++) {
            for(auto e : G[i]) {
                t.add_edge(i, e.first, e.second);
            }
        }
        return t;
    }
};

int main(){ 
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<long long, long long>>> G(n);
    for(int i = 0; i < m; i++) {
        int s, t, w;
        std::cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    auto MST = kruskal::make_mst(G);
    std::cout << MST.get_cost() << std::endl;
}
