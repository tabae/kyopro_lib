# Dijkstra

## 機能
Dijkstra法で最短経路問題を解く。
- sample_list : 隣接リストを想定
- sample_list : グリッドを想定（いわゆる迷路問題みたいな）

## 使い方 (隣接リスト)
```
dijkstra(G, dist, initial_pos);
```
- `G` : `vector<vector<pair<ll,ll>>>`の隣接リスト
    - first : 頂点のインデックス
    - second : 移動コスト
- `dist` : `vector<ll>` で始点からの距離が格納される。
    - INFで初期化しておくこと。
- `initial_pos` : `ll`で初期位置のインデックス

## 使い方（グリッド）
```
dijkstra(dist, maze, initial_pos);
```
- `dist` : `vector<vector<ll>>` で始点からの距離が格納される。
    - INFで初期化しておくこと。
- `maze` : `vector<string>`の迷路情報
    - 迷路問題でないなら不要
- `initial_pos` : `pair<ll,ll>`の初期位置のインデックス
    - first : h方向（i方向）
    - second : w方向 (j方向)

## 注意
ともに0-index。

## Sample
- Single Source Shortest Path (AOJ) : sample_list.cpp
- ABC007 C 幅優先探索 : sample_grid.cpp