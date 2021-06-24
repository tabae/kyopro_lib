#include <string>
#include <vector>

std::vector<std::pair<char, int>> run_length_encoding(const std::string& s) {
    std::vector<std::pair<char, int>> res;
    int n = s.size();
    char prev = -1;
    int cur = 1;
    for(int i = 0; i < n; i++) {
        if(prev == s[i]) cur++;
        else {
            if(prev != -1) res.push_back({prev, cur});
            prev = s[i];
            cur = 1;
        } 
    }
    res.push_back({prev, cur});
    return res;
}

template<class T>
std::vector<std::pair<T, int>> run_length_encoding(const std::vector<T>& s){
    std::vector<std::pair<T, int>> res;
    int n = s.size();
    int prev = -1;
    int cur = 1;
    for(int i = 0; i < n; i++) {
        if(prev == s[i]) cur++;
        else {
            if(prev != -1) res.push_back({prev, cur});
            prev = s[i];
            cur = 1;
        } 
    }
    res.push_back({prev, cur});
    return res;
}

int main() {

}