#include <bits/stdc++.h>

#include <atcoder/fenwicktree>
typedef struct _median_manage {
    // vaiables
    atcoder::fenwick_tree<int> fw;  
    int nmax, real_size;
    // construct
    _median_manage(int _n) : nmax(_n), real_size(_n+10) {
        fw = atcoder::fenwick_tree<int>(real_size);
    }
    bool insert(int i) {
        if(fw.sum(i, i+1) == 1) return false;
        fw.add(i, 1);
        return true;
    }
    bool erase(int i) {
        if(fw.sum(i, i+1) == 0) return false;
        fw.add(i, -1);
        return true;
    }
    long long get_median() {
        int sum = fw.sum(0, real_size);
        assert(sum > 0);
        int l = -1, r = real_size;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if(fw.sum(0, m+1) < (sum+1) / 2) l = m;
            else r = m; 
        }
        return r;
    }
    long long get_lnum() {
        int sum = fw.sum(0, real_size);
        if(sum == 0) return 0;
        return (sum+1) / 2 - 1;
    }
    long long get_rnum() {
        int sum = fw.sum(0, real_size);
        return sum / 2;
    }
    long long get_sum() {
        return fw.sum(0, real_size);
    }
} medi;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    } 

    medi md(n);
    int rmax = n+10;
    atcoder::fenwick_tree<long long> inv(rmax), idx(rmax);
    long long ninv = 0;
    for(int i = 0; i < n; i++) {
        // update
        inv.add(q[i], 1);
        idx.add(q[i], q[i]);
        assert(md.insert(q[i]));
        // count inversion
        ninv += inv.sum(q[i]+1, rmax);
        // print ans
        auto med = md.get_median();
        auto lnum = md.get_lnum();
        auto rnum = md.get_rnum();
        long long l = med * lnum - idx.sum(0, med) - lnum * (lnum+1) / 2;
        long long r = idx.sum(med+1, rmax) - med * (rnum) - (rnum) * (rnum+1) / 2;
        cout << ninv + l + r << (i == n-1 ? "\n" : " ");
    }
    return 0;
}