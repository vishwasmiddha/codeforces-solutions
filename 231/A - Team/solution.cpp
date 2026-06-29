#include <iostream>
 
int main (){
    int n;
    std::cin >> n;
    int a;
    int b;
    int c;
    int amount = 0;
    for(int i=0;i<n;i++){
        std::cin >> a >> b >> c;
        int num = a+b+c;
        if (num>1){
            amount++;
        }
    }
    std::cout << amount;
}