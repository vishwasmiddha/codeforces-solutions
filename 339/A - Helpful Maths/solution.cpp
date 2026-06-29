#include <iostream>
using namespace std;
 
int main(){
    int num1=0;
    int num2=0;
    int num3=0;
    string line;
    cin >> line;
    for(int i=0;i<line.length();i++){
        if(line[i]=='1'){
            num1++;
        }
        if(line[i]=='2'){
            num2++;
        }
        if(line[i]=='3'){
            num3++;
        }
    }
    string outp = "";
    for(int i=0;i<num1;i++){
        outp += "1+";
    }
    for(int i=0;i<num2;i++){
        outp += "2+";
    }
    for(int i=0;i<num3;i++){
        outp += "3+";
    }
    outp.pop_back();
    std::cout << outp;
 
}