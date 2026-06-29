#include <iostream>
 
int main (){
    int a;
    int b;
    int c;
    int d;
    int e;
    int lmove;
    int rmove;
    for(int r = 1;r<=5;r++){
        std::cin >> a >> b >> c >> d >> e;
        if(a==1){
            rmove = r>3?r-3:3-r;
            lmove = 2;
            break;
        }
        if(b==1){
            rmove = r>3?r-3:3-r;
            lmove = 1;
            break;
        }
        if(c==1){
            rmove = r>3?r-3:3-r;
            lmove = 0;
            break;
        }
        if(d==1){
            rmove = r>3?r-3:3-r;
            lmove = 1;
            break;
        }
        if(e==1){
            rmove = r>3?r-3:3-r;
            lmove = 2;
            break;
        }
    }
std::cout << lmove + rmove;
}