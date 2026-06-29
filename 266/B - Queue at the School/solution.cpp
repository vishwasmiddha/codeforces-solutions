#include <iostream>
#include <string>
using namespace std;
 
int main(){
    
    int n;
    cin >> n;
    int t;
    cin >> t;
    string line;
    cin >> line;
    string line2 = line;
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            if(line[j]=='B'&&line[j+1]=='G'){
                line2[j]='G';
                line2[j+1]='B';
            }
        }
        line = line2;
    }
    cout << line;
    
}