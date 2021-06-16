#include <iostream>
#include <vector>
#include <numeric>

struct union_find {
public:
    union_find(int _n) : n(_n), group(_n) {
        parent.resize(n);
        nums.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int root(int x) {
        if(parent[x] == x) return x;
        parent[x] = root(parent[x]);
        return parent[x];
    }
    // Merge y to x
    void merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx != ry){
            group--;
            parent[ry] = rx;
            nums[rx] += nums[ry];
        }
    }
    bool same(int x, int y) {
        return (root(x) == root(y));
    }
    int size() {
        return group;
    }
    int size(int x) {
        return nums[root(x)];
    }
private:
    int n, group;
    std::vector<int> parent;
    std::vector<int> nums;
};  

int main() {
    int n, q;
    std::cin >> n >> q;
    union_find uf(n);
    while(q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if(t == 0) uf.merge(u, v);
        else std::cout << uf.same(u, v) << "\n";
    }    
}
