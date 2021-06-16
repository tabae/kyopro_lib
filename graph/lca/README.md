# LCA

## 機能
- LCA (最小共通祖先)

## 使い方
```
lca t(G, root);
int lca_uv = t.get_lca(u, v);
int d_uv = t.get_dist(u, v);
bool f = t.is_on_path(u, v, x);
```

## コンストラクタ
```
lca t(vector<vector<T>> &G, int root);
```
Input:
- vector<vector<T>> G: 隣接リスト．`T`は整数型．
- root: 根．デフォルトで0．

## get_lca()
```
int get_lca(int u, int v);
```
頂点`u`と`v`のLCAを返す

## get_dist()
```
int get_dist(int u, int v);
```
頂点`u`と`v`間の距離を返す．現在は辺の長さ1のみに対応

## is_on_path()
```
bool is_on_path(int u, int v, int a);
```
頂点`u`と`v`の最短経路に頂点`a`が存在するかを判定する．

## Reference
- https://algo-logic.info/lca/

## Verify
- https://judge.yosupo.jp/submission/50582