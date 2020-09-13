#include <bits/stdc++.h>
using namespace std;

/*-------------ここから---------------*/
using _ll = long long;
vector<_ll> _max_subtree, _sum_subtree;
_ll _centroid1(vector<vector<_ll>>& G, _ll cur, _ll par, _ll N) {
    _ll mx = 0, sum = 0;
    for(auto g : G[cur]) {
        if(g == par) continue;
        _ll tmp = _centroid1(G, g, cur, N);
        sum += tmp;
        mx = max(mx, tmp);
    }
    mx = max(mx, N - sum - 1);
    _max_subtree[cur] = mx;
    _sum_subtree[cur] = sum;
    return sum + 1;
}
vector<_ll> _centroid2(_ll N) {
    vector<_ll> res;
    _ll mn = 1LL<<60;
    for(_ll i = 0; i < N; i++) mn = min(mn, _max_subtree[i]);
    for(_ll i = 0; i < N; i++) if(_max_subtree[i] == mn) res.push_back(i);
    return res;
}
vector<_ll> find_centroids(vector<vector<_ll>>& G, _ll N) {
    _max_subtree = vector<_ll>(N, 0);
    _sum_subtree = vector<_ll>(N, 0);
    _centroid1(G, 0, -1, N);
    return _centroid2(N);
}
/*-------------ここまで---------------*/

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> G(n);
    for(ll i = 0; i < n-1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto v = find_centroids(G, n);
    if(v.size() == 1) {
        for(ll i = 0; i < 2; i++) cout << 1 << " " << G[0][0]+1 << endl;
        return;
    }
    ll cut;
    for(auto g : G[v[1]]) {
        if(g == v[0]) continue;
        cut = g;
        break;
    }
    cout << v[1]+1 << " " << cut+1 << endl;
    cout << v[0]+1 << " " << cut+1 << endl; 
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}