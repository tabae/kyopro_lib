#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

namespace geo {
    
    template<class T = double>
    struct point2D {
        T x, y;
        point2D() : x(0), y(0) {}
        point2D(T x, T y) : x(x), y(y) {}
    };

    template<class T = double>
    struct line2D {
        point2D<T> p1, p2;
        line2D() {}
        line2D(point2D<T> p1, point2D<T> p2) : p1(p1), p2(p2) {}
        T x1() { return p1.x; }
        T y1() { return p1.y; }
        T x2() { return p2.x; }
        T y2() { return p2.y; }
    };

    template<class T>
    double dist(point2D<T> u, point2D<T> v) {
        double dx = u.x - v.x;
        double dy = u.y - v.y;
        double dist = sqrt(dx * dx + dy * dy);
        return dist;
    }
    
    template<class T>
    double dist(line2D<T> line, point2D<T> point){
        double a = line.y2() - line.y1();
        double b = line.x2() - line.x1();
        double c = -line.x1() * a + line.y1() * b;
        double d = abs(a * point.x - b * point.y + c) / sqrt(a * a + b * b);
        return d;
    }

    template<class T>
    bool cross(line2D<T> l1, line2D<T> l2){        
        auto a = l1.p1, b = l1.p2;
        auto c = l2.p1, d = l2.p2;
        double s, t;
        s = (a.x - b.x) * (a.y - c.y) - (a.y - b.y) * (a.x - c.x);
        t = (a.x - b.x) * (a.y - d.y) - (a.y - b.y) * (a.x - d.x);
        if (s * t >= 0) return false;    
        s = (c.x - d.x) * (c.y - a.y) - (c.y - d.y) * (c.x - a.x);
        t = (c.x - d.x) * (c.y - b.y) - (c.y - d.y) * (c.x - b.x);
        if (s * t >= 0) return false;
        return true;
    }

}

using namespace geo;

int main() {

}