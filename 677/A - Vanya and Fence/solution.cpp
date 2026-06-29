#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int n;
    int h;
    cin >> n >> h;
    int w=0;
    int h2;
    string inp;
    for(int i=0;i<n;i++){
        cin >> h2;
        w++;
        if(h2>h){
            w++;
        }
    }
    cout << w;
}