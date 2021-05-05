# 最小全域木（kruskal法）

最小全域木を求めます．

## 使い方
```
kruskal::mst t(n);
t.add_edge(u, v, w);
ll cost = t.build();
```

## コンストラクタ
```
kruskal::mst t(n);
```
- n: 頂点数

## add
```
void add(ll vertex1, ll vertex2, ll cost)
void add(ll vertex1, ll vertex2, ll cost, ll id)
```
- vertex1, vertex2: 辺が結ぶ頂点（双方向）
- cost: 辺のコスト
- id: 辺のID（任意）

## build
```
ll t.build();
```
最小全域木を作る．返り値に総コストを持つ．

## get_cost
```
ll get_cost()
```
最小全域木に使われた辺の総コストを返す．

## get_used_edges
```
vector<ll> get_used_edges()
```
最小全域木に使われた辺のindexのリストを返す．

## get_tree
```
vector<vector<pair<ll,ll>>> get_tree()
```
{頂点，コスト}のpairを持つ隣接リストで最小全域木を返す．

## kruskal::mst_cost
```
mst mst_cost(vector<vector<pair<ll,ll>>> G)
```
Input:
- {頂点，コスト}のpairを持つ隣接リスト

Output:
- build済みのmstを返す

## 注意
- 0-indexedです．

## Verify
- https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5451657#1