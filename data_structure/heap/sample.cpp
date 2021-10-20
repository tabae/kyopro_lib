#include <vector>
#include <iostream>

template<class T>
struct heap {
    int next;
    std::vector<T> values;
    heap() : next(0) {}
    void push(T v) {
        int cur = next;
        if(values.size() <= cur) {
            values.push_back(v);
        } else {
            values[cur] = v;
        }
        while(cur) {
            int par = (cur-1) / 2;
            if(values[cur] < values[par]) { 
                swap(values[cur], values[par]);
                cur = par;
            } else {
                break;
            }
        }
        next++;
    }
    T top() {
        assert(!values.empty());
        return values.front();
    }
    T pop() {
        assert(!values.empty());
        int cur = 0;
        next--;
        swap(values[cur], values[next]);
        while(true) {
            int to = -1;
            if(2*cur + 2 < next) {
                to = (values[2*cur + 1] < values[2*cur + 2] ? 2*cur + 1 : 2*cur + 2);
            } else if(2*cur + 1 < next) {
                to = 2*cur + 1;
            } else {
                break;
            }
            if(values[cur] > values[to]) {
                swap(values[cur], values[to]);
                cur = to;
            } else {
                break;
            }
        }
        return values[next];
    }
    bool empty() {
        return next == 0;
    }
    bool size() {
        return next;
    }
    void dump() {
        for(int i = 0; i < next; i++) {
            cerr << values[i] << (i == next-1 ? "\n" : " ");
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    heap<int> t;
    for(auto e : a) t.push(e);
    for(int i = 0; i < n; i++) std::cout << t.pop() << (i == n-1 ? "\n" : " ");
    return 0;
}