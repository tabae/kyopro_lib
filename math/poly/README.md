# Poly

## 機能
多項式の足し算，引き算，掛け算を行う．

## 使い方

### 初期化
```
poly<int> a = {1, 2, 3}; // 3*x^2 + 2*x + 1 
poly<int> b; // 0 
```
- initializer_listを用いて初期化

### 足し算
```
auto c = poly<int>({1, 2, 3}) + poly<int>({1, 2});
// c = {2, 4, 3}
```

### 引き算
```
auto c = poly<int>({1, 2, 3}) - poly<int>({1, 2});
// c = {0, 0, 3}
```

## 掛け算
```
auto c = poly<int>({1, 2, 3}) * poly<int>({0, 1});
// c = {0, 1, 2, 3}
```

### `format()`
```
auto c = poly<int>({0, 1, 0}).format();
// c = {0, 1}
```

## サンプル
- GCD of Polynomials (Codeforces #453 Div2-D) : ./sample.cpp