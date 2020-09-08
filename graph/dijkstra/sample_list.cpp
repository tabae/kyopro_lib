#include <bits/stdc++.h>
using namespace std;

/*-------ここから--------*/
using _ll = long long;
using _pl = pair<_ll, _ll>;
void dijkstra(vector<vector<_pl>> &G, vector<_ll> &dist, _ll initial_pos) {
    priority_queue<_pl, vector<_pl>, greater<_pl>> que;
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
            que.push({next_cost, next_pos});
        }
    }
}
/*-------ここまで--------*/

using ll = long long;
using pl = pair<ll, ll>;

int main() {
    int v, e, initial_pos;
    cin >> v >> e >> initial_pos;
    vector<vector<pl>> G(v);
    for(int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});   
    }
    const ll inf = 1e18;
    vector<ll> dist(v, inf);
    dijkstra(G, dist, initial_pos);
    for(int i = 0; i < v; i++){
        if(dist[i] == inf) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}