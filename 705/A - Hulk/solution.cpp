#include <iostream>
#include <string>
#include <bitset>
//#include <algorithm.h>
using namespace std;
#include <bits/stdc++.h> 
 
int main(){
    int n;
    cin >> n;
    string word = "";
    bool love = false;
    for(int i=0;i<n;i++){
        if(love){
            word += "I love that ";
        } else {
            word += "I hate that ";            
        }
        love = !love;
    }
    word.pop_back();
    word.pop_back();
    word.pop_back();
    word.pop_back();
    word.pop_back();
    word+= "it";
    cout << word;
}