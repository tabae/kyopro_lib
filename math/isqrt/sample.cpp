#include <iostream>

// return maximum x such that x^2 <= n
// requirements: n <= 4e18 
long long isqrt(long long n) {
    long long res;
    long long l = 0, r = 2000000001;
    while(r - l > 1) {
        long long m = l + (r - l) / 2;
        if(m * m <= n) l = m;
        else r = m;
    }
    return l;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << isqrt(n) << std::endl;
}