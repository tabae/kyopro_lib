#include <iostream>

constexpr long long nmax = 1000000000000000000; // 10^18

// nmaxより大きくなるとき, nmax+1を返す
long long ofpow(long long a, long long p) {
    if(a > nmax) return nmax + 1;
    if(a == 0) return 0;
    long long res = 1;
    for(int i = 0; i < p; i++) {
        if(nmax / a < res) return nmax + 1;
        res *= a;
    }
    return res;
}

// nmaxより大きくなるとき, nmax+1を返す
long long ofmul(long long a, long long b) {
    if(a > nmax || b > nmax) return nmax + 1;
    if(a == 0 || b == 0) return 0;
    if(nmax / a < b) return nmax + 1;
    return a * b;
}

int main() {
    int n;
    std::cin >> n;
    long long prod = 1;
    bool zero = false;
    bool of = false;
    for(int i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        prod = ofmul(prod, a);
        if(prod == nmax+1) of = true;
        if(a == 0) zero = true;
    }
    if(zero) prod = 0;
    else if(of) prod = -1;
    std::cout << prod << std::endl;
}