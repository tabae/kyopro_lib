# 高速素因数分解 (osa_k法)

## 機能

次のようなクエリに答える。

N個の整数a_1, a_2, ..., a_nを素因数分解せよ．
- 2 <= n <= 10^6
- 1 <= a_i <= 10^6

## 計算量
- 前処理 O(max(a) log log max(a))
- クエリ O(log a_i)

## 使い方

### 前処理
- `PRIME_FACTORIZE_MAX`に最大値+1を設定

### クエリ
- `factorize(N)`で`N`を素因数分解する．
- 結果は`pair<long long, long long>`の`vector`で返ってくる (first ^ second).
```
vector<pair<long long, long long>> v = factorize(a[i]);
```

## サンプルコード

- サンプル: ./sample.cpp
- ABC177 - E Coprime: ./abc177_e.cpp