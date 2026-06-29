#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int x;
    int y;
    int z;
    int xt=0;
    int yt=0;
    int zt=0;
    for(int i=0;i<n;i++){
        cin >> x >> y >> z;
        xt = xt + x;
        yt = yt + y;
        zt = zt + z;
    }
    if(xt==0&&yt==0&&zt==0){
        cout << "YES";
    } else {
        cout << "NO";
    }
}