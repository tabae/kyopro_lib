# Dijkstra

## 機能
Dijkstra法で最短経路問題を解く。
- sample_list : 隣接リストを想定
- sample_grid : グリッドを想定（いわゆる迷路問題みたいな）

## 使い方 (隣接リスト)
```
dijkstra(G, dist, initial_pos);
```
- `vector<vector<pair<ll,ll>>> G` : 隣接リスト
    - first : 頂点のインデックス
    - second : 移動コスト
- `vector<ll> dist` : で始点からの距離が格納される。
    - INFで初期化しておくこと。
- `ll initial_pos` : 初期位置のインデックス

## 使い方（グリッド）
```
dijkstra(dist, maze, initial_pos);
```
- `vector<vector<ll>> dist` : 始点からの距離が格納される。
    - INFで初期化しておくこと。
- `vector<string> maze` : 迷路情報
    - 迷路問題でないなら不要
- `pair<ll,ll> initial_pos` : 初期位置のインデックス
    - first : h方向（i方向）
    - second : w方向 (j方向)

## 使い方（経路復元）
```
auto [dist, from] res = dijkstra(G, initial_pos);
auto route = path(from, start, goal);
```
- `vector<vector<pair<ll,ll>>> G` : 隣接リスト
    - first : 頂点のインデックス
    - second : 移動コスト
- `ll initial_pos` : 初期位置のインデックス
- 返り値(`pair<vector<ll>, vector<ll>>`)
    - first : initial_posからの距離
    - second : 各頂点にどこから来たか
- `ll start, goal`: 復元する経路の始点と終点
    - start は initial_posと同一
    - goalは到達可能である必要あり
- `vector<ll> route` :startからgoalまでの経路

## 注意
ともに0-index。

## Sample
- Single Source Shortest Path (AOJ) : sample_list.cpp
- ABC007 C 幅優先探索 : sample_grid.cpp