# Rolling Hash

## 機能
ロリハです．

## 使い方
```
rollinghash roli(s);
long long hash = roli.get(0, 3);
```

## Constructor
```
rollinghash(string s);
```
- sのロリハを構築します．

## get
```
long long get(int l, int r);
```
- s[l:r)のハッシュを返します．**半開区間**です．

## 注意
- 128bit整数サポート環境でしか動かないよ

## Verify
- https://atcoder.jp/contests/abc141/submissions/27000039