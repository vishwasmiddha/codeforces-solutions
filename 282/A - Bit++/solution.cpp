#include <iostream>
 
int main (){
    int n;
    std::cin >> n;
    int x=0;
    for(int i=0;i<n;i++){
        std::string state;
        std::cin >> state;
        if(state=="X++"||state=="++X"){
            x++;
        } else {
            x--;
        }
    }
    std::cout << x;
}