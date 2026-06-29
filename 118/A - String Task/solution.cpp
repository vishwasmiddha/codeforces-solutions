#include <iostream>
using namespace std;
int main(){
    string word;
    cin >> word;
    string wrd = "";
    for(int i=0;i<word.length();i++){
        word[i]=tolower(word[i]);
        if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='y'){
        } else {
            wrd += '.';
            wrd += word[i];
        }
    }
    cout << wrd;
}