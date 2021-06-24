#include <iostream>

long long comb(int n, int k) {
    if(n < k || n < 0 || k < 0) return 0;
    if(k == 0 || k == n) return 1;
    long long res = 1;
    for(int v = 1; v <= k; v++) {
        res *= (n + 1 - v);
        res /= v;
    }
    return res;
}

int main() {
    std::cout << comb(29, 14) << std::endl;
}