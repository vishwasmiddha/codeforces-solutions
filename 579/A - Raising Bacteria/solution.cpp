#include <iostream>
int main(){
    long long x;
    std::cin >> x;
    std::cout << __builtin_popcountll(x);
}