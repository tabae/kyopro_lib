# Warshall Floyed 法

## 機能
- O(V^3)で最短経路問題を解く

## 使い方
```
wf::warshallFloyed(dist);
```

## wf::warshallFloyd
```
void wf::warshallFloyed(vector<vector<T>> dist);
```
任意の2頂点間の最短距離を計算する（辺のコストは非負）
Input:
- `vector<vector<T>> dist` : 隣接行列, Tは整数型

## wf::warshallFloyedNeg
```
bool wf::warshallFloyedNeg(vector<vector<T>> dist, T inf);
```
任意の2頂点間の最短距離を計算する（辺のコストは負になりうる）
Input:
- `vector<vector<T>> dist` : 隣接行列，Tは整数型
- `T inf`：2頂点間に経路が存在しないことを表すための任意の値．経路長としてあり得ないほど大きい/小さい値を設定すること．
Output:
- `bool` : 負の閉路があれば`false`，無ければ`true`.

## Verify
- https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5607715#1