# median_manage

## 概要
- indexの集合を管理する．
- indexを追加したり削除したりする．
- 現在追加されているindexの中央値をかえす．

## 使い方
- AtCoder Libraryを使用しています．

### コンストラクタ
```
medi md(int n);
```
- n: indexは[0, n)の中の値のみ

### `insert()`
```
bool res = md.insert(int i);
```
- `i`を追加する
- すでに`i`が追加されているとfalseが帰ってくる

### `erase()`
```
bool res = md.erase(int i);
```
- `i`を削除する
- `i`が存在しないとfalseが帰ってくる

### `get_medinan()`
```
int res = get_median();
```
- 中央値を返す．
- 要素数が偶数なら，左側の中央値(?)を返す．

### `get_lnum()`
```
int res = get_lnum();
```
- 中央値の左側にある要素数を返す．中央値は含まない．

### `get_rnum()`
- 上の右版．

### `get_sum()`
- 現在追加されている要素数を返す．
- get_lnum() + get_rnum() + 1 == get_sum()

## Sample
- Div2 609E - K Integers: ./sample.cpp