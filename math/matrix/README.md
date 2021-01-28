# matrix

## 機能
- 行列積と行列累乗

## 使い方
### `matrix<class T>`
```
matrix<int> a = {{1, 1}, {1, 2}};
matrix<int> a(n, vector<int>(n));
```
vector< vector< class T > >

### `matrix<T> E(int n)`
n x n の単位行列を返す

### `matrix<T> matMul(matrix<T> a, matrix<class T>b)`
a x b を返す．正方行列でなくともよい

### `vector<T> vecMul(matrix<T> a, vector<T> b)`
a x b を返す．

### `matrix<T> matPow(matrix<T> a, ll p)`
a ^ p を返す．O(log a.size()^3 p)


## サンプルコード

- AOJ Fibonacci Number: ./sample.cpp