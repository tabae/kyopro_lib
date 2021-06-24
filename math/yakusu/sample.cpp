#include <vector>
#include <algorithm>

std::vector<long long> yakusu(long long n){
    std::vector<long long> ret;
    for(long long i = 1; i * i <= n; i++){
        if(n % i != 0) continue;
        ret.push_back(i);
        if(i*i != n) ret.push_back(n/i);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    
}