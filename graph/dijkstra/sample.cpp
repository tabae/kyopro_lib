#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

namespace dijkstra {

    using ll = long long;
    using pl = std::pair<ll, ll>;
    constexpr ll inf = 1LL<<60;

    std::pair<std::vector<ll>, std::vector<ll>> search(const std::vector<std::vector<pl>> &G, ll initial_pos) {
        std::vector<ll> from(G.size());
        std::vector<ll> dist(G.size(), inf);
        std::priority_queue<pl, std::vector<pl>, std::greater<pl>> que;
        dist[initial_pos] = 0;
        que.push({0, initial_pos});
        while(!que.empty()) {
            auto q = que.top();
            que.pop();
            auto cur_cost = q.first;
            auto cur_pos = q.second;
            if(cur_cost > dist[cur_pos]) continue;
            for(const auto& e : G[cur_pos]) {
                auto next_pos = e.first;
                auto next_cost = cur_cost + e.second;
                if(next_cost >= dist[next_pos]) continue;
                dist[next_pos] = next_cost;
                from[next_pos] = cur_pos;
                que.push({next_cost, next_pos});
            }
        }
        return make_pair(dist, from);
    }

    std::pair<std::vector<ll>, std::vector<ll>> search(const std::vector<std::vector<ll>> &G, ll initial_pos) {
        std::vector<std::vector<std::pair<ll,ll>>> pseudoG(G.size());
        for(int i = 0; i < G.size(); i++) {
            for(const auto& e : G[i]) {
                pseudoG[i].push_back({e, 1});
            }
        }
        return search(pseudoG, initial_pos);
    }

    std::vector<ll> restore(std::vector<ll>& from, ll start, ll goal) {
        assert(from[goal] != -1);
        std::vector<ll> res;
        ll cur = goal;
        while(cur != start) {
            res.push_back(cur);
            cur = from[cur];
        }
        res.push_back(cur);
        reverse(res.begin(), res.end());
        return res;
    }

}

int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    std::vector<std::vector<std::pair<long long, long long>>> G(n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    auto [dist, from] = dijkstra::search(G, s);
    if(dist[t] == dijkstra::inf) {
        std::cout << -1 << std::endl;
        return 0;
    }
    auto path = dijkstra::restore(from, s, t);
    std::cout << dist[t] << " " << path.size()-1 << "\n";
    for(int i = 0; i < path.size()-1; i++) {
        std::cout << path[i] << " " << path[i+1] << "\n";
    }
    return 0;
}
