#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cmath>
#include <limits>

namespace geo {
    
    using ll = long long;
    const double inf = std::numeric_limits<double>::max();

    template <class T>
    struct P {
        T x, y;
        P() {;}
        P(const T& _x, const T &_y) : x(_x), y(_y) {;}
        P(const std::pair<T, T>& lhs) {
            x = lhs.first;
            y = lhs.second;
        }
        P & operator = (const std::pair<T, T> & lhs) {
            x = lhs.first;
            y = lhs.second;
        }
        P(const std::initializer_list<T>& lhs) {
            x = *lhs.begin();
            y = *(lhs.begin()+1);
        }
        P & operator = (const std::initializer_list<T>& lhs) {
            x = *lhs.begin();
            y = *(lhs.begin()+1);
            return *this;
        }
    };

    template <class T>
    struct L {
        P<T> p1, p2;
    };

    template<class T>
    double dist(const P<T>& a, const P<T>& b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    template<class T>
    bool line_cross(const L<T>& l1, const L<T>& l2){        
        P<T> a = l1.p1, b = l1.p2;
        P<T> c = l2.p1, d = l2.p2;
        double s, t;
        s = (a.x - b.x) * (a.y - c.y) - (a.y - b.y) * (a.x - c.x);
        t = (a.x - b.x) * (a.y - d.y) - (a.y - b.y) * (a.x - d.x);
        if (s * t >= 0) return false;    
        s = (c.x - d.x) * (c.y - a.y) - (c.y - d.y) * (c.x - a.x);
        t = (c.x - d.x) * (c.y - b.y) - (c.y - d.y) * (c.x - b.x);
        if (s * t >= 0) return false;
        return true;
    }

    template<class T> 
    P<double> midpoint(const P<T>& a, const P<T>& b) {
        return P(0.5 * (a.x + b.x), 0.5 * (a.y + b.y));
    }

    template<class T> 
    double gradient(const P<T>& a, const P<T>& b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        if(dx == 0) return inf;
        else return dy / dx;
    }

    template<class T> 
    double gradient(const L<T>& l) {
        return gradient<T>(l.p1, l.p2);
    }

    template<class T> 
    double intercept(const P<T>& a, const P<T>& b) {
        double grad = gradient<T>(a, b);
        if(grad == inf) return inf;
        else a.y - grad * a.x;
    };

    template<class T>
    double intercept(const P<T>& a, const double& grad) {
        if(grad == inf) return inf;
        else return a.y - grad * a.x;
    }

    template<class T>
    double intercept(const L<T>& l) {
        return intercept<T>(l.p1, l.p2);
    }

    template<class T>
    std::pair<double, double> vertical_bisector(const P<T>& a, const P<T>& b) {
        double base_grad = gradient<T>(a, b);
        double grad;
        if(base_grad == inf) grad = 0;
        else if(base_grad == 0) grad = inf;
        else grad = - 1.0 / base_grad;
        P<T> mid = midpoint<T>(a, b);
        return std::make_pair<double, double>(grad, intercept<T>(mid, grad));
    }    

    template<class T>
    std::pair<double, double> vertical_bisector(const L<T>& l) {
        return vertical_bisector<T>(l.p1, l.p2);
    }

    namespace integer {

        using P = geo::P<ll>;
        using L = geo::L<ll>;

        ll square_dist(P a, P b) {
            ll dx = a.x - b.x;
            ll dy = a.y - b.y;
            return dx * dx + dy * dy;
        }

        bool line_cross(L l1, L l2){        
            P a = l1.p1, b = l1.p2;
            P c = l2.p1, d = l2.p2;
            ll s, t;
            s = (a.x - b.x) * (a.y - c.y) - (a.y - b.y) * (a.x - c.x);
            t = (a.x - b.x) * (a.y - d.y) - (a.y - b.y) * (a.x - d.x);
            if (s * t >= 0) return false;    
            s = (c.x - d.x) * (c.y - a.y) - (c.y - d.y) * (c.x - a.x);
            t = (c.x - d.x) * (c.y - b.y) - (c.y - d.y) * (c.x - b.x);
            if (s * t >= 0) return false;
            return true;
        }

    }

}

void solve() {
    std::cout << geo::integer::square_dist({0, 0}, {3, 4}) << std::endl;
    geo::integer::P a, b;
    a = {2, 3};
    b = a;
}

int main() {
    solve();
    return 0;
}
