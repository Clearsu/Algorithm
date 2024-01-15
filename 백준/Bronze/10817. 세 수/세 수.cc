#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        std::cout << b << '\n';
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        std::cout << a << '\n';
    } else {
        std::cout << c << '\n';
    }
    return 0;
}