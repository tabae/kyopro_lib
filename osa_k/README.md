# 高速素因数分解 (osa_k法)

## 例題

$N$個の整数$a_1, a_2, ..., a_n$を素因数分解せよ．
- $2 \leq n \leq 10^6$
- $1 \leq a_i \leq 10^6$

## 計算量
- 前処理 $O(max(a)log\ log\ max(a))$
- 各素因数分解 $(log\ a_i)$

## 使い方

### 前処理
- $max(a)$を引数にして宣言．
- コンストラクタが前処理を行う．
```
osa_k p(MAX_A);
```

### クエリ
- `p.factorize(素因数分解する数)`で素因数分解を行う．
- 結果は`pair<long long, long long>`の`vector`で返ってくる ($first ^ {second}$).
```
vector<pair<long long, long long>> v = p.factorize(a[i]);
```

## サンプルコード

- サンプル: ./sample.cpp
- ABC177 - E Coprime: ./abc177_e.cpp