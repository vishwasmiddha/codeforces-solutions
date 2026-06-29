#include <iostream>
using namespace std;
 
int main(){
    string word;
    cin >> word;
    int small=0;
    int big=0;
    for(char ch:word){
        if (ch == tolower(ch)){
            small++;
        } else {
            big++;
        }
    }
    if (big>small){
        for(int i = 0;i<word.length();i++){
            word[i] = toupper(word[i]);
        }
    } else {
        for(int i = 0;i<word.length();i++){
            word[i] = tolower(word[i]);
        }
    }
    cout << word;
}