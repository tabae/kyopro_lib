# 高速素因数分解 (osa_k法)

## 機能

次のようなクエリに答える。

N個の整数a_1, a_2, ..., a_nを素因数分解せよ．
- 2 <= n <= 10^6
- 1 <= a_i <= 10^6

### 計算量
- 前処理 O(max(a) log log max(a))
- クエリ O(log a_i)

## 使い方
```
vector<pair<int,int>> v = osa_k::prime_factorize(n);
```

## コンストラクタ
- エラトステネスの篩で最小の素因数を列挙

## osa_k::prime_factorize
```
vector<pair<int,int>> osa_k::prime_factorize(int n);
```
- `n`を素因数分解する．
- 素因数をキーに昇順でソートされている

## Verify
- https://atcoder.jp/contests/abc177/submissions/23705983