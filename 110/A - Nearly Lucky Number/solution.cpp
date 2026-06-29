#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string word;
    int num=0;
    cin >> word;
    for(char ch:word){
        if(ch=='4'||ch=='7'){
            num++;
        }
    }
    string num1 = to_string(num);
    bool lucky=true;
    for(char ch:num1){
        if(ch!='4'&&ch!='7'){
            cout << "NO";
            lucky=false;
            break;
        }
    }
    if(lucky){
        cout << "YES";
    }
}