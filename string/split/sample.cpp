#include <string>
#include <vector>
#include <iostream>

// s.split(c) in python
std::vector<std::string> split(std::string s, char c){
    std::vector<std::string> res;
    s.push_back(c); // 番兵
    int n = s.size();
    std::string cur;
    for(int i = 0; i < n; i++) {
        if(s[i] == c) {
            res.push_back(cur);
            cur = "";
        } else {
            cur.push_back(s[i]);
        }
    }
    return res;
}

int main() {
    for(auto e : split("23,24,25", ',')) {
        std::cout << e << std::endl;
    }
}