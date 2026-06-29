#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int eh;
    string difficulty = "EASY";
    for(int i = 0;i<n;i++){
        cin >> eh;
        if(eh==1){
            difficulty = "HARD";
        }
        
    }
    cout << difficulty;
}