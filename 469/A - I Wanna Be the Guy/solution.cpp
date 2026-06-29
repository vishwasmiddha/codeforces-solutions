#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    string truth(n,'F');
 
    int n1;
    int n2;
    
    cin >> n1;
    for(int i=0;i<n1;i++){
        int level;
        cin >> level;
        truth[level-1]='T';
    }
    
    cin >> n2;
    for(int i=0;i<n2;i++){
        int level;
        cin >> level;
        truth[level-1]='T';
    }
    
    bool man = true;
    
    for(char ch:truth){
        if(ch=='F'){
            man = false;
        }
    }
    if(man){
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }
}