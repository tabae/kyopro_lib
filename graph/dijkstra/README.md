# Dijkstra法

## 機能
1. Dijkstra法で最短経路問題を解く
2. 経路復元を行う

## 使い方
```
pair<vector<ll>, vector<ll>> res = dijkstra::search(G, initial_pos);
vector<ll> path = dijkstra::restore(res.second, start, goal);
```

## dijkstra::search
Input:
- `vector<vector<pair<ll,ll>>> G`: 隣接リスト
- `ll initial_pos`: 始点

Output:
- `vector<ll> res.first`: 始点からの最短距離．到達不可能なら`dijkstra::inf`.
- `vector<ll> res.second`: 経路情報．各頂点にどこから来たのか.

## dijkstra::restore
Input:
- `vector<ll> res.second`: 上述
- `ll start`: 始点
- `ll goal`: 終点

制約:
- `goal`が到達可能であること(`res.second[goal] != dijkstra::inf`)．

Output:
- `vector<ll> path`: 経路

## 注意
- ともに0-indexed．
- `vector<vector<ll>> G`を渡すと，全辺コスト1とみなして最短経路を探索する．

## Verify
- https://judge.yosupo.jp/submission/46798