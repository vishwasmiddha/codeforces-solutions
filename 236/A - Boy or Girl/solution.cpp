#include <iostream>
 
using namespace std;
 
bool inside(string s, char c){
    bool val = false;
    for(int i=0;i<s.length();i++){
        if(s[i]==c){
            val = true;
            break;
        }
    }
    return val;
}
 
int main(){
    string s = "";
    string inp;
    cin >> inp;
    for (char ch:inp){
        if(!inside(s,ch)){
            s = s + ch;
        }
    }
    if(s.length()%2==0){
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }
}