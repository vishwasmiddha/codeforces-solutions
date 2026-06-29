#include <iostream>
using namespace std;
 
int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    for(int i=0;i<s1.length();i++){
        int l1 = (int)tolower(s1[i]);
        int l2 = (int)tolower(s2[i]);
        if(l1>l2){
            std::cout << 1;
            break;
        } else if (l1<l2){
            std::cout << -1;
            break;
        } else if (l1==l2&&i==s1.length()-1){
            std::cout << 0;
        }
    }
}