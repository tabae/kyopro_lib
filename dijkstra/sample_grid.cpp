#include <bits/stdc++.h>
using namespace std;

/*---------ここから---------*/
using _ll = long long;
using _pl = pair<_ll, _ll>;
using _tl = pair<_ll, _pl>;
void dijkstra(vector<vector<_ll>> &dist, vector<string> &maze, _pl initial_pos) {
    /* 遷移方向を変更したいときはここを変更する。*/
    const _ll dx[4] = {1, -1, 0, 0};
    const _ll dy[4] = {0, 0, 1, -1};

    _ll H = maze.size();
    _ll W = maze[0].size();
    auto ng = [&](_ll i, _ll j) {
        return (i < 0 || j < 0 || i >= H || j >= W);
    };

    priority_queue<_tl, vector<_tl>, greater<_tl>> que;
    que.push({0, initial_pos});
    dist[initial_pos.first][initial_pos.second] = 0;

    while(!que.empty()) {
        auto q = que.top();
        que.pop();
        auto cur_cost = q.first;
        auto cur_i = q.second.first;
        auto cur_j = q.second.second;
        for(_ll k = 0; k < 4; k++) {
            auto next_i = cur_i + dx[k];
            auto next_j = cur_j + dy[k];
            if(ng(next_i, next_j)) continue;

            /* コストを変更したいときはここを変更する。*/
            auto next_cost = cur_cost + 1;

            if(dist[next_i][next_j] <= next_cost) continue;

            /* 遷移条件を変更したいときはここを変更する。*/
            if(maze[next_i][next_j] == '#') continue;

            dist[next_i][next_j] = next_cost;
            que.push({next_cost, {next_i, next_j}});
        }
    }
}
/*---------ここまで---------*/

using ll = long long;

int main() {
    ll r, c, sx, sy, gx, gy;
    cin >> r >> c;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vector<string> maze(r);
    for(ll i = 0; i < r; i++) cin >> maze[i];
    const ll inf = 1e18;
    vector<vector<ll>> dist(r, vector<ll>(c, inf));
    dijkstra(dist, maze, {sy, sx});
    cout << dist[gy][gx] << endl;
    return 0;
}