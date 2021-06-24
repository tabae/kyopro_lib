# str2dec

## 機能
10進数の浮動小数点数を受け取り，10^X倍した整数として返す

## 使い方
```
long long str2dec(string s, int shift);
```

## 注意
shiftした結果，なお整数にならない場合はバグります

## Verify
- https://atcoder.jp/contests/abc169/submissions/23718493