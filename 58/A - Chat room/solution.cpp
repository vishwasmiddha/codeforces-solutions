#include <iostream>
using namespace std;
 
int main(){
    string hi;
    cin >> hi;
    int n = hi.length();
    int ind;
    bool hel = false;
    for(int i=0;i<n;i++){
        if(hi[i]=='h'){
            for(int j=i+1;j<n;j++){
               if(hi[j]=='e') {
                   for(int k=j+1;k<n;k++){
                       if(hi[k]=='l'){
                           for(int l=k+1;l<n;l++){
                               if(hi[l]=='l'){
                                   for(int m=l+1;m<n;m++){
                                       if(hi[m]=='o'){
                                           hel = true;
                                       }
                                   }
                               }
                           }
                       }
                   }
               }
            }
        }
    }
    if(hel){
        cout << "YES";
    } else {
        cout << "NO";
    }
}