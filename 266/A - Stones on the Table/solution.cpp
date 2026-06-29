#include <iostream>
using namespace std;
 
int main(){
    int length;
    cin >> length;
    string word;
    cin>> word;
    int removes = 0;
    for(int i = 0;i<length-1;i++){
        if(word[i]==word[i+1]){
            removes++;
        }
    }
    cout << removes;
}