#include <iostream>
 
int main (){
    int m;
    int n;
    std::cin >> m >> n;
    if(m%2==1&&n%2==1){
        std::cout << (m*n-1)/2;
    } else {
        std::cout << (m*n)/2;
    }
}