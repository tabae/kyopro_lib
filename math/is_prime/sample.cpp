#include <iostream>

bool is_prime(long long n) {
    if(n == 1) return false;
    for(long long val = 2; val * val <= n; val++) {
        if(n % val == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int p;
        std::cin >> p;
        ans += is_prime(p);
    }
    std::cout << ans << std::endl;
}