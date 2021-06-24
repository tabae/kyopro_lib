#include <vector>
#include <string>
#include <cassert>
#include <iostream>

// Requirements:
// - `v` must be matrix.
template <class T> 
void rotate(std::vector<T>& v) {
    int h = v.size(), w = v[0].size();
    std::vector<T> res(w, T(h, '.'));
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
        res[j][h-1-i] = v[i][j];
    }
    v = res;
}

template<class T>
void print(std::vector<T> v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j] << (j == v[i].size()-1 ? "\n" : " ");
        }
    }
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}};
    print(a);
    rotate(a);
    print(a);
    std::vector<std::string> s = {"abc", "def"};
    print(s);
    rotate(s);
    print(s);
}