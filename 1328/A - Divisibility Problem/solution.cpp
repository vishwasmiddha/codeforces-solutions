#include <iostream>
using namespace std;
 
int main(){
    int loops;
    cin >> loops;
    for(int i=0;i<loops;i++){
        int a,b;
        cin >> a >> b;
        if(a%b==0){
            cout << 0 << endl;
        } else {
            cout << b-(a%b) << endl;
        }
    }
}