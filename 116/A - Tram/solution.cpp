#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int n;
    cin>> n;
    int come;
    int go;
    int num=0;
    int max=0;
    for(int i=0;i<n;i++){
        cin >> go >> come;
        num = num + come - go;
        if(num>max){
            max = num;
        }
    }
    cout << max;
}