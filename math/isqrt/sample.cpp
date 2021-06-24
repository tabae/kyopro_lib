#include <iostream>
#include <cmath>

// return such maximum x that x^2 <= n 
long long isqrt(long long n) {
    long long res;
    double r = std::sqrt(n);
    for(long long i = std::max<long long>(0, r - 10); i < r + 10; i++) {
        if(i * i > n) {
            res = i - 1;
            break;
        }
    }
    return res;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << isqrt(n) << std::endl;
}