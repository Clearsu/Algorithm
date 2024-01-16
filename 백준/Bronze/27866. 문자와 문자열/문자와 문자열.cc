#include <iostream>
#include <string>

int main() {
    std::string str;
    int n;
    
    std::cin >> str >> n;
    std::cout << str[n - 1] << '\n';
}