#include <iostream>
#include <numeric>

// - a/b :  a is numerator, b is denominator
// - default value is 1
struct rational {
    using ll = long long;
    static constexpr ll inf = 1LL<<60;
    ll a, b; 
    void normalize(ll &a, ll &b) {
        if(a == 0 && b == 0) {
            a = 0;
            b = 0;
        } else if(b == 0) {
            a = 1;
        } else if(a == 0) {
            b = 1;
        }
        if(a < 0) {
            a = -a;
            b = -b;
        }
        ll g = std::gcd(a, b);
        if(g != 0) {
            a /= g;
            b /= g;
        }
    }
    rational() : a(0), b(1) {;}
    rational(ll _a, ll _b) : a(_a), b(_b) {
        normalize(a, b);
    } 
    void set_max() {
        a = 0;
        b = inf;
    }
    void set_min() {
        a = 0;
        b = -inf;
    }
    bool operator ==(const rational& rhs) const {
        return (this->a == rhs.a && this->b == rhs.b);
    }
    bool operator <(const rational& rhs) const {
        if(this->is_min() || rhs.is_max()) return true;
        if(this->is_max() || rhs.is_min()) return false;
        ll x = (this->a) * rhs.b;
        ll y = (this->b) * rhs.a;
        return x < y;
    }
    bool operator <=(const rational& rhs) const {
        if(this->is_min() || rhs.is_max()) return true;
        if(this->is_max() || rhs.is_min()) return false;
        ll x = (this->a) * rhs.b;
        ll y = (this->b) * rhs.a;
        return x <= y;
    }
    bool operator >(const rational& rhs) const {
        if(this->is_min() || rhs.is_max()) return false;
        if(this->is_max() || rhs.is_min()) return true;
        ll x = (this->a) * rhs.b;
        ll y = (this->b) * rhs.a;
        return x > y;
    }
    bool operator >=(const rational& rhs) const {
        if(this->is_min() || rhs.is_max()) return false;
        if(this->is_max() || rhs.is_min()) return true;
        ll x = (this->a) * rhs.b;
        ll y = (this->b) * rhs.a;
        return x >= y;
    }
    rational operator +(const rational& rhs) const {
        if(this->is_max() || this->is_min() || this->b == 0) return *this;
        if(rhs.is_max() || rhs.is_min() || rhs.b == 0) return rhs;
        ll g = std::gcd(this->b, rhs.b);
        ll b = this->b / g * rhs.b;
        ll a = this->a * b / this->b + rhs.a * b / rhs.b;
        return rational(a, b);
    }
    rational operator -(const rational& rhs) const {
        if(this->is_max() || this->is_min() || this->b == 0) return *this;
        if(rhs.is_max() || rhs.is_min() || rhs.b == 0) return rhs;
        ll g = std::gcd(this->b, rhs.b);
        ll b = this->b / g * rhs.b;
        ll a = this->a * b / this->b - rhs.a * b / rhs.b;
        return rational(a, b);
    }
    rational operator *(const rational& rhs) const {
        if(this->is_max() || this->is_min() || this->b == 0) return *this;
        if(rhs.is_max() || rhs.is_min() || rhs.b == 0) return rhs;
        ll a = this->a * rhs.a;
        ll b = this->b * rhs.b;
        ll g = std::gcd(a, b);
        a /= g;
        b /= g;
        return rational(a, b);
    }
    rational operator /(const rational& rhs) const {
        if(this->is_max() || this->is_min() || this->b == 0) return *this;
        if(rhs.is_max() || rhs.is_min() || rhs.a == 0) return rhs;
        ll a = this->a * rhs.b;
        ll b = this->b * rhs.a;
        ll g = std::gcd(a, b);
        a /= g;
        b /= g;
        return rational(a, b);
    }
    bool is_max() const {
        return (a == 0 && b == inf); 
    }
    bool is_min() const {
        return (a == 0 && b == -inf);
    }
    double to_real() const {
        if(b == 0) return (a > 0 ? inf : -inf);
        return 1. * a / b;
    }
    ll to_int() const {
        if(b == 0) return (a > 0 ? inf : -inf);
        return a / b;
    }
};

int main() {
    rational a(1, 3), b(2, 3), x(1, 3);
    auto c  = a + b;
    std::cout << c.to_int() << std::endl;
    c = a + x;
    std::cout << c.to_real() << std::endl;
}