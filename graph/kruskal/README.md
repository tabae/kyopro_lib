# 最小全域木（kruskal法）

## 機能
最小全域木を求めます．

## 使い方

### コンストラクタ
```
kruskal::krus t(n);
```
- n: 頂点数

### `add`
```
t.add(ll cost, ll vertex1, ll vertex2);
```
- cost: 辺のコスト
- vertex1, vertex2: 辺が結ぶ頂点（双方向）

### `build`
```
ll total_cost = t.build();
```
最小全域木を作る．返り値に総コストを持つ．

### `get_used_edges`
```
vector<ll> idx = t.get_used_edges();
```
最小全域木に使われた辺のindexのリストを返す．indexに対応する辺情報は，
```
edge e = t.get_edge(ll i);
```
で取得可能．

## Sample
ABC065 D - Built? : ./sample.cpp