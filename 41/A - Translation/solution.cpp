#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string s;
    string t;
    string rev = "";
    cin >> s;
    cin >> t;
    for(int i=s.length()-1;i>=0;i--){
        rev += s[i];
    }
    if(rev==t){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}