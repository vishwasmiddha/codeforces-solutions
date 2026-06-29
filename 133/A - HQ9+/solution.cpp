#include <bits/stdc++.h>
#include <cctype>
using namespace std;
 
bool check (string s2){
    for (auto c:s2){
        if (c=='H' | c=='Q' | c=='9') return true;
    }
    return false;
}
 
int main(){
    string s;
    cin >> s;
    cout << (check(s)?"YES":"NO");
}