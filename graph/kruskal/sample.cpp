#include <bits/stdc++.h>

/*---------------ここから---------------*/
namespace kruskal {

    using ll = long long;

    typedef struct union_find {

        std::vector<ll> parent;
        std::vector<ll> nums;
        
        union_find(ll n) {
            parent.resize(n);
            nums.resize(n, 1LL);
            for(ll i = 0; i < n; i++) parent[i] = i;
        }
        
        ll root(ll x) {
            if(parent[x] == x) return x;
            parent[x] = root(parent[x]);
            return parent[x];
        }
        
        void unite(ll x, ll y) {
            ll rx = root(x);
            ll ry = root(y);
            if(rx != ry){
                parent[rx] = ry;
                nums[ry] += nums[rx];
            }
        }
        
        bool same(ll x, ll y) {
            ll rx = root(x);
            ll ry = root(y);
            if(rx == ry) return true;
            return false;
        }
        
        ll size(ll x) {
            return nums[root(x)];
        }

    } uf;

    typedef struct EdgeInfo {
        ll cost, u, v, id;
        EdgeInfo() {;};
        EdgeInfo(ll _cost, ll _u, ll _v, ll _id) : cost(_cost), u(_u), v(_v), id(_id) {};    
        ~EdgeInfo() {;};
    } edge;
    bool operator<(const edge& t1, const edge& t2) { return (t1.cost < t2.cost); };
    bool operator>(const edge& t1, const edge& t2) { return (t1.cost > t2.cost); };
    bool operator<=(const edge& t1, const edge& t2) { return (t1.cost <= t2.cost); };
    bool operator>=(const edge& t1, const edge& t2) { return (t1.cost >= t2.cost); };

    typedef struct krus {

        ll N, M; // N: #nodes, M: #edges
        std::vector<edge> E;
        std::vector<ll> used_edges;
        ll cost;

        krus(ll _N) : N(_N), cost(-1) {;}

        void add(ll cost, ll u, ll v, ll id) {
            E.push_back(edge(cost, u, v, id));
        }

        void add(ll cost, ll u, ll v) {
            ll id = E.size();
            E.push_back(edge(cost, u, v, id));
        }

        ll build() {
            uf t(N);
            cost = 0;
            used_edges.clear();
            std::sort(E.begin(), E.end());

            for(auto e : E) {
                if(!t.same(e.u, e.v)) {
                    t.unite(e.u, e.v);
                    cost += e.cost;
                    used_edges.push_back(e.id);
                }
            }

            return cost;
        }

        ll get_cost() {
            if(cost == -1) build();
            return cost;
        }

        edge get_edge(ll i) {
            return E[i];
        }

        std::vector<ll> get_used_edges() {
            if(cost == -1) build();
            return used_edges;
        }

    } krus;
}
/*---------------ここまで---------------*/

typedef struct town { int x, y, id; } town;

int main(){
    int n;
    std::cin >> n;
    std::vector<town> t(n);

    for(int i = 0; i < n; i++) {
        std::cin >> t[i].x >> t[i].y;
        t[i].id = i;
    }

    kruskal::krus k(n);
    sort(t.begin(), t.end(), [](auto l, auto r) {return l.x < r.x;});
    for(int i = 0; i < n-1; i++) k.add(t[i+1].x-t[i].x, t[i+1].id, t[i].id);
    sort(t.begin(), t.end(), [](auto l, auto r) {return l.y < r.y;});
    for(int i = 0; i < n-1; i++) k.add(t[i+1].y-t[i].y, t[i+1].id, t[i].id);
    
    std::cout << k.build() << std::endl;
    return 0;
}
