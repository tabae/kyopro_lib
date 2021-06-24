#include <iostream>
#include <numeric>

std::pair<long long, long long> gradient(long long x1, long long y1, long long x2, long long y2) {
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    if(dx < 0) {
        dx = -dx;
        dy = -dy;
    }
    if(dx == 0 && dy == 0) return {0, 0};
    else if(dx == 0) return {0, 1};
    else if(dy == 0) return {1, 0};
    long long g = std::gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
    return std::make_pair(dx, dy);
}

int main() {
    
}