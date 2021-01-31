#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

// For debug
// Ref: https://qiita.com/ysuzuki19/items/d89057d65284ba1a16ac
#define dump(var)  do{std::cerr << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cerr << e << "\n";}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cerr << e << " "; } std::cerr << "\n";}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ std::cerr << "\n"; for(const auto& v : vv){ view(v); } }
template<typename T> void dump_cout(const T& v) { for(long long i = 0; i < v.size(); i++) std::cout << v[i] << (i == v.size()-1 ? "\n" : " "); }

template<class T>
struct poly {
    int n;
    vector<T> v;
    poly(int n = 0) : n(n), v(vector<T>(n, 0)) {}
    poly(initializer_list<T> init) : v(init.begin(), init.end()), n(init.end() - init.begin()) {}
    int size() const { return n; }
    T& operator[] (const int& i) { return v[i]; }
    const T& operator[] (const int& i) const { return v[i]; }
    void format() {
        for(ll i = n-1; i >= 0; i--) if(v[i] != 0) { 
            v = vector<T>(v.begin(), v.begin()+i+1);
            n = i+1; return;
        }
        v.clear(); n = 0;
    }
};
template<class T> 
poly<T> operator+(const poly<T>& t1, const poly<T> &t2) {
    int mx = max(t1.size(), t2.size());
    poly<T> res(mx);
    rep(i, 0, mx) {
        if(i < t1.size()) res[i] += t1[i];
        if(i < t2.size()) res[i] += t2[i];
    }
    return res;
}
template<class T> 
poly<T> operator-(const poly<T>& t1, const poly<T> &t2) {
    int mx = max(t1.size(), t2.size());
    poly<T> res(mx);
    rep(i, 0, mx) {
        if(i < t1.size()) res[i] += t1[i];
        if(i < t2.size()) res[i] -= t2[i];
    }
    return res;
}
template<class T> 
poly<T> operator*(const poly<T>& t1, const poly<T>& t2) {
    int mx = t1.size() + t2.size() - 1;
    poly<T> res(mx);
    rep(i, 0, t1.size()) {
        rep(j, 0, t2.size()) {
            res[i+j] += t1[i] * t2[j];
        }
    }    
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vector<poly<ll>> p(n+2);
    p[0] = {0}; p[1] = {1};
    rep(i, 2, n+2) {
        p[i] = (p[i-1] * poly<ll>({0, 1})) + p[i-2];
        rep(j, 0, p[i].size()) p[i][j] %= 2;
    }
    p[n+1].format(); p[n].format();
    cout << p[n+1].size()-1 << "\n";
    rep(i, 0, p[n+1].size()) cout << p[n+1][i] << (i == p[n+1].size()-1 ? "\n" : " ");
    cout << p[n].size()-1 << "\n";
    rep(i, 0, p[n].size()) cout << p[n][i] << (i == p[n].size()-1 ? "\n" : " ");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
