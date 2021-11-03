# 有理数ライブラリ

## 機能
- 有理数を扱うことができます．

## 使い方
```
rational a(1, 3), b(2, 3); // 1/3 , 2/3
rational c = a + b; // 1
```

## 分子，分母
- `a` : 分子
- `b` : 分母

## Constructor
```
rational(long long a, long long b);
```
- aが分子，bが分母

## set_max(), set_min()
```
void set_max();
void set_min();
```
- 上限値，下限値に設定します．

## is_max(), is_min()
```
bool is_max();
bool is_min();
```
- 上限値，下限値を判定します．

## to_int(), to_real()
```
long long to_int();
double to_real();
```
- 有理数を整数，浮動小数点数の形に変換して返します．

## Operator
- 四則演算と比較演算をサポートしています．
- 当然オーバーフローしたら終わりです．

## Verify
- https://atcoder.jp/contests/abc225/submissions/26911986