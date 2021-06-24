# modulo

## 機能
- 二項係数のmod
- 階乗のmod
- 階乗のmod逆元

## modulo::fac
```
mint modulo::fac(int n);
```
n! % mod を計算する 

### modulo::ifac
```
mint modulo::ifac(mint n);
```
n! のmod逆元

## modulo::comb
```
mint module::comb(int n, int k);
```
comb(n, k) % mod

## 注意
- atcoder library の modint を使用しています

## Verify
- https://atcoder.jp/contests/abc021/submissions/23716060