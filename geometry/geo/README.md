# geo

## 機能
- 2点間距離
- 点と直線の距離
- 直線交差判定

## geo::point2D
- 2次元平面の座標を表す構造体

## geo::line2D
- 2次元平面上の直線を表す構造体
- 直線が通り2点を用いて表す

## geo::dist
```
double geo::dist(point2D a, point2D b);
double geo::dist(line2D line, point2D point);
```
- 2点間距離，または，点と直線の距離を返す

## geo::cross
```
bool geo::cross(line2D a, line2D b);
```
- 直線`a`と直線`b`が交差しているならば`true`を返す

## Verify
- してないよ