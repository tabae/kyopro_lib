# matrix

## 機能
- 行列積と行列累乗

## 使い方
```
mat::matrix<int> a = {{1, 1}, {1, 2}};
mat::matrix<int> a(n, vector<int>(n));
```

## mm::E
```
mat::matrix<T> E(int n);
```
n x n の単位行列を返す

## mm::matMul
```
mat::matrix<T> matMul(matrix<T> a, matrix<T> b);
```
a x b を返す．正方行列でなくともよい

## mm::vecMul
```
vector<T> vecMul(matrix<T> a, vector<T> b);
```
a x b を返す．

## mm::matPow
```
matrix<T> matPow(matrix<T> a, ll p)
```
a ^ p を返す．O(log a.size()^3 p)


## Verify
- https://judge.yosupo.jp/submission/51344