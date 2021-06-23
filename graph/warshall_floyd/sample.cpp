#include <iostream>
#include <vector>

namespace wf {
    // There is no edge with negative cost
    template<class T>
    void warshallFloyed(std::vector<std::vector<T>> &d) {
        int n = d.size();
        for(int i = 0; i < n; i++) d[i][i] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                }
            }
        }
    }
    // There are edges with negative cost.
    // If graph has negative cycle, return false
    template<class T>
    bool warshallFloyedNeg(std::vector<std::vector<T>> &d, T inf) {
        bool res = true;
        int n = d.size();
        auto chmin = [&](T &a, T b) {
            if(a == inf) a = b;
            else if(b == inf) ;
            else a = std::min(a, b);
        };
        auto addinf = [&](T a, T b) -> T {
            if(a == inf || b == inf) return inf;
            else return a + b;
        };
        for(int i = 0; i < n; i++) chmin(d[i][i], 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    chmin(d[j][k], addinf(d[j][i], d[i][k]));
                }
            }
        }
        for(int i = 0; i < n; i++) if(d[i][i] < 0) res = false;
        return res;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> s(m), t(m), w(m);
    for(int i = 0; i < m; i++) std::cin >> s[i] >> t[i] >> w[i];
    const long long inf = 1LL<<60;
    std::vector dist(n, std::vector<long long>(n, inf));
    for(int i = 0; i < m; i++) dist[s[i]][t[i]] = w[i];
    if(!wf::warshallFloyedNeg(dist, inf)) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == inf) std::cout << "INF";
            else std::cout << dist[i][j];
            std::cout << (j == n-1 ? "\n" : " ");
        }
    }
}

int main() {
    solve();
    return 0;
}