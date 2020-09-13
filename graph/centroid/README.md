# 木の重心列挙

## 機能
木の重心を列挙します．
- 木の重心：木からその頂点を取り除いたときに，分断された木の最大サイズが最も小さくなるもの

## 使い方
```
auto v = find_centroids(G, n);
```
- v : 重心のインデックス
    - vector<long long>

- G : 隣接リスト
    - vector<vector<long long>>

- n : 頂点数
    - long long

## Sample
- sample.cpp : Codeforces Div2.670 C