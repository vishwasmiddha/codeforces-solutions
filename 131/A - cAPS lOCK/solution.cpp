#include <bits/stdc++.h>
#include <cctype>
using namespace std;
int main(){
    string s;
    cin >> s;
    if (s.size()==1){
        cout << ((islower(s[0])) ? (char)toupper(s[0]) : (char)tolower(s[0]));
    } else {
        string s2 = s.substr(1,s.size()-1);
        bool capson = true;
        for (auto c:s2){
            if (islower(c)){
                capson = false;
            }
        }
    
    if (capson){
        for (auto c:s){
            if(isupper(c)){
                cout << (char)tolower(c);
            } else {
                cout << (char)toupper(c);
            }
        }   
        
    } else {
        cout << s;
    }
    }
    
}