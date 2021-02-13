#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

namespace dijkstra {

    /*
    How to use:
        dijkstra:
            - input: 
                - vector<vector<pair<ll,ll>>> G
                    - Adjaceny list.
                    - The first of pair is a vertex and the second is a cost.
                - ll initial_pos
                    - Initial vertex of dijkstra.
            - output:
                - First vector<ll>
                    - Distances from initial_pos to i-th vertex. 
                    - If i-th vertex is unreachable, dijkstra::inf is contained.
                - Second vector<ll>
                    - A vertex which visited before visiting i-th vertex. 
                    - If i-th vertex is unreachable, -1 is contained.
        path:
            - input:
                - vector<ll> from
                    - Second vector<ll> of returned vectors from the function dijkstra.
                - ll start
                    - Initial vertex of dijkstra. 
                    - It is required to be same as `initial_pos` in dijkstra.
                - ll goal
                    - The end vertex of path
            - output:
                - vector<ll>
                    - The path from start to goal 
    */

    using ll = long long;
    using pl = pair<ll, ll>;
    constexpr ll inf = 1LL<<60;

    pair<vector<ll>, vector<ll>> dijkstra(vector<vector<pl>> &G, ll initial_pos) {
        vector<ll> from(G.size());
        vector<ll> dist(G.size(), inf);
        priority_queue<pl, vector<pl>, greater<pl>> que;
        dist[initial_pos] = 0;
        que.push({0, initial_pos});
        while(!que.empty()) {
            auto q = que.top();
            que.pop();
            auto cur_cost = q.first;
            auto cur_pos = q.second;
            for(auto e : G[cur_pos]) {
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

    vector<ll> path(vector<ll>& from, ll start, ll goal) {
        assert(from[goal] != -1);
        vector<ll> res;
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

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> G(n);
    rep(i, 0, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back({b, 1});
        G[b].push_back({a, 1});
    }    
    auto [dist, from] = dijkstra::dijkstra(G, 0);
    rep(i, 1, n) if(dist[i] == dijkstra::inf) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    rep(i, 1, n) cout << from[i]+1 << endl;
    #ifdef VERIFY
    rep(i, 0, n) {
        for(auto e : dijkstra::path(from, 0, i)) {
            cerr << e+1 << " -> ";
        } 
        cerr << endl;
    }
    #endif
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
