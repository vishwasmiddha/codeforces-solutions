#include <iostream>
using namespace std;
int main(){
    int n;
    string field;
    cin >> field;
    n = field.length();
    string dangerous = "NO";
    int danger = 1;
    for(int i = 0;i<n;i++){
        if(field[i]==field[i+1]){
            danger++;
        } else {
            danger=1;
        }
        if(danger==7){
            dangerous = "YES";
        }
    }
    cout << dangerous;
}