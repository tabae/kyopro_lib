# Union Find

## 機能
- 連結成分を管理します．

## 使い方
```
union_find uf(n);
uf.merge(a, b);
int rx = uf.root(x);
bool f = uf.same(a, b);
int sz = uf.size(a);
int sz2 = uf.size();
```

## コンストラクタ
```
union_find uf(n)
```
Input:
- `int n`: グラフの頂点数

## merge
```
void merge(int a, int b)
```
頂点`a`と`b`の間に辺を追加する．

## root
```
int root(int x)
```
頂点`x`が属する連結成分の代表元を返す．

## same
```
bool same(int a, int b)
```
頂点`a`と`b`が連結か判定する．

## size
```
int size()
int size(int x)
```
引数がない場合，連結成分の数を返す．

引数がある場合，頂点`x`が属する連結成分の大きさを返す．

## 注意
- 0-indexed.

## Verify
- https://judge.yosupo.jp/submission/46812