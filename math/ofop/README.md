# ofop

## 機能
オーバーフロー検知つき演算，pow と mul

## ofpow
```
ll ofpow(ll a, ll p);
```
a ^ p > nmax なら nmax+1 を返す
それ以外は普通にpowを計算

## ofmul
```
ll ofmul(ll a, ll b);
```
a * b > nmax なら nmax+1 を返す
それ以外は普通にa * bを計算

## Verify
- ofmul: https://atcoder.jp/contests/abc169/submissions/23719594