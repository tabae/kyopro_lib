# LCA

## 機能
木でLCAを見つける

## 使い方

### コンストラクタ
```
lca::lca t(vector<vector<lca::edge>> G, ll root);
```
- G: 隣接リスト，`lca::edge`はデフォルトで`ll`.
- root: 根．デフォルトで0．

### `get_lca()`
```
ll x = t.get_lca(ll u, ll v);
```
- u, vのLCAを返す

### `get_dist()`
```
ll d = t.get_dist(ll u, ll v);
```
- u, v 間の距離を返す

### `is_on_path()`
```
bool f = t.is_on_path(ll u, ll v, ll a);
```
- u -> vのパスに頂点aが存在するか？

## Samples
- AOJ GRL_5_C - Lowest Common Ancestor: ./sample.cpp
- ABC104 D - 閉路: ./abc104_d.cpp