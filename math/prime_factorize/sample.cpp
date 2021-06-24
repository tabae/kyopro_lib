#include <vector>
#include <algorithm>

std::vector<std::pair<long long, long long>> prime_factorize(long long n){
    std::vector<std::pair<long long, long long>> ret;
    for(long long a = 2; a * a <= n; a++){
        if(n % a != 0) continue;
        long long ex = 0;
        while(n % a == 0){
            ex++;
            n /= a;
        }
        ret.push_back({a, ex});
    }
    if(n != 1) ret.push_back({n, 1});
    return ret;
}

int main() {
    
}