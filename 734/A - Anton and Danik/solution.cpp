#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int a=0;
    int d=0;
    string win;
    cin >> win;
    for(char ch:win){
        if(ch=='A'){
            a++;
        } else {
            d++;
        }
    }
    if(a==d){
        cout << "Friendship";
    } else if(a>d) {
        cout << "Anton";
    } else {
        cout << "Danik";
    }
}