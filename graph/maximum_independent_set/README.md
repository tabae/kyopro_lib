# 最大独立集合

最大独立集合を一つ返します．

## 使い方
```
vector<int> mis = max_independent_set(G);
```
## max_independent_set
```
vector<int> max_independent_set(vector<vector<int>> G)
```
Input:
- `vector<vector<int>> G`: 隣接リスト

Output:
- 最大独立集合を一つ返します．

## 注意
- 0-indexedです．
- **重複辺および自己ループは隣接リストに含まないでください.**

## Reference
- http://kurkur.hatenablog.com/entry/2018/02/08/022629

## Verify
- https://judge.yosupo.jp/submission/46841