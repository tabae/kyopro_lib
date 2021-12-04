#include <iostream>
#include <string>
#include <cassert>

std::string zfill(const std::string& s, size_t size) {
    assert(s.size() <= size);
    std::string res = std::string(size - s.size(), '0') + s;
    return res;
}

std::string zfill(const long long& n, size_t size) {
    return zfill(std::to_string(n), size);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << "AGC" << zfill(n + (n>=42), 3) << std::endl;
    return 0;
}