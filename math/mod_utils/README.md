# mod utils

## 機能
modulo系のごっちゃ詰め(にする予定)．`atcoder::modint*` を使用．

## 使い方

### パラメータ
- `mint`: エイリアス，お好みの`atcoder::modint*`をどうぞ．
- `MOD_UTILS_NMAX`: (N-1)! % MOD まで前計算します．

### `fac()`
```
mint f = fac(mint n);
```
n! % mod 

### `inv_fac()`
```
mint if = inv_fac(mint n);
```
n! のmod逆元

### `nck()`
```
mint com = nck(n, k);
```
nCk % mod

## Sample
- ABC110 D - Factorization: ./sample.cpp