#include <string>
#include <cmath>
#include <iostream>

/*
オーバーフローには気を付けよう！
Inputs:
    string s        : string representing a decimal number, such as 123.4, 0.123, 123.
    int shift_size  : shift size, formally, this function return s * 10 ^ shift_size.
Output:
    Return s * 10 ^ shift_size as long long.
*/
long long str2dec(std::string s, int shift_size) {
    auto pos = s.find('.');
    auto pw = [](long long a, int p) -> long long {
        long long res = 1;
        for(int i = 0; i < p; i++) res *= a;
        return res;
    };
    if(pos == std::string::npos) return atoll(s.c_str()) * pw(10LL, shift_size); // If s is an integer
    long long res = atoll(s.substr(0, pos).c_str()) * pw(10LL, shift_size); 
    res += atoll(s.substr(pos+1, s.size()-pos-1).c_str()) * pw(10LL, shift_size - (s.size()-pos-1));
    return res;
}

int main() {
    std::string s;
    long long a, b;
    std::cin >> a >> s;
    b = str2dec(s, 2);
    long long ans = a * b / 100;
    std::cout << ans << std::endl;
} 