# 木の重心列挙

## 機能
木の重心を列挙します．
- 木の重心：木からその頂点を取り除いたときに，分断された木の最大サイズが最も小さくなるもの

## 使い方
```
auto v = centroid::find(G);
```
- G : 隣接リスト
    - vector<vector<long long>>

## Verify
- sample.cpp : Codeforces Div2.670 C