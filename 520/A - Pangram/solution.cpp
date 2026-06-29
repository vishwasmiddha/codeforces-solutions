#include <iostream>
#include <bitset>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    bitset<26> b1;
    string word;
    cin >> word;
    for(int i=0;i<n;i++){
        b1.set(tolower(word[i])-'a');
    }
    if(b1.all()){
        cout << "YES";
    } else {
        cout << "NO";
    }
}