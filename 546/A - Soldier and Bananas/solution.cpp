#include <iostream>
using namespace std;
 
int main(){
    int cost;
    int money;
    int num;
    cin >> cost >> money >> num;
    int rmoney = cost*num*(num+1)/2;
    if (rmoney-money >0){
        cout << rmoney - money;
    } else {
        cout << 0;
    }
}