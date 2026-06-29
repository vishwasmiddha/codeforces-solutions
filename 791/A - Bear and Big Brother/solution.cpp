#include <iostream>
using namespace std;
 
int main(){
    int a;
    int b;
    int years = 0;
    cin >> a >> b;
    while(a<=b){
        years++;
        a = a*3;
        b = b*2;
    }
    cout << years;
}