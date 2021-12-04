#include <string>
#include <vector>
#include <cassert>
#include <iostream>

std::vector<std::pair<char, long long>> run_length_encoding(const std::string& s) {
    std::vector<std::pair<char, long long>> res;
    int n = s.size();
    char xev = -1;
    char prev = xev;
    long long cur = 1;
    for(int i = 0; i < n; i++) {
        assert(s[i] != xev);
        if(prev == s[i]) cur++;
        else {
            if(prev != xev) res.push_back({prev, cur});
            prev = s[i];
            cur = 1;
        } 
    }
    if(prev != xev) res.push_back({prev, cur});
    return res;
}

template<class T>
std::vector<std::pair<T, long long>> run_length_encoding(const std::vector<T>& s){
    std::vector<std::pair<T, long long>> res;
    int n = s.size();
    T xev = -1;
    T prev = xev;
    long long cur = 1;
    for(int i = 0; i < n; i++) {
        assert(s[i] != xev);        
        if(prev == s[i]) cur++;
        else {
            if(prev != xev) res.push_back({prev, cur});
            prev = s[i];
            cur = 1;
        } 
    }
    if(prev != xev) res.push_back({prev, cur});
    return res;
}

int main() {
    std::string s = "mississippi";
    for(auto [val, count] : run_length_encoding(s)) {
        std::cout << val << " x " << count << std::endl;
    }
}