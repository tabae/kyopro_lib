#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>

std::string add(std::string a, std::string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = std::max(a.size(), b.size());
    while(a.size() < n) a.push_back('0');
    while(b.size() < n) b.push_back('0');
    std::string res;
    int age = 0;
    for(int i = 0; i < n; i++) {
        int cur = age + (a[i] - '0') + (b[i] - '0');
        res.push_back(cur % 10 + '0');
        age = cur / 10;
    }
    if(age) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}

std::string sub(std::string a, std::string b) {
    int n = std::max(a.size(), b.size());
    assert(a.size() > b.size() || a >= b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a.size() < n) a.push_back('0');
    while(b.size() < n) b.push_back('0');
    std::string res;
    int age = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < '0' || a[i] < b[i]) {
            assert(i != n-1);
            a[i] += 10;
            a[i+1] -= 1;
        }
        int cur = (a[i] - b[i]) + '0';
        res.push_back(cur);
    }
    while(!res.empty()) {
        if(res.back() == '0') res.pop_back();
        else break;
    }
    if(res.empty()) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}

// a >= b ?
bool comp(std::string a, std::string b) {
    if(a.size() > b.size()) return true;
    if(a.size() < b.size()) return false;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    }
    return true;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << add(a, b) << std::endl;
}