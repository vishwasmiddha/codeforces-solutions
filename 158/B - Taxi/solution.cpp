#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int num1=0;
    int num2=0;
    int num3=0;
    int num4=0;
    int size;
    int taxi=0;
    for(int i=0;i<n;i++){
        cin >> size;
        if(size==1){
            num1++;
        }
        if(size==2){
            num2++;
        }
        if(size==3){
            num3++;
        }
        if(size==4){
            num4++;
        }
    }
    if(num3>num1&&num2%2==0){
        taxi = num4 + num3 + num2/2;
    } else if(num3>num1&&num2%2==1){
        taxi = num4 + num3 + num2/2 + 1;
    } else if(num1>num3&&num2%2==0&&(num1-num3)%4==0){
        taxi = num4 + num3 + num2/2 + (num1-num3)/4;
    } else if(num1>num3&&num2%2==0&&(num1-num3)%4!=0){
        taxi = num4 + num3 + num2/2 + (num1-num3)/4 + 1;
    } else if(num1>num3&&num2%2==1&&(num1-num3)%4==0){
        taxi = num4 + num3 + num2/2 + (num1-num3)/4 + 1;
    } else if(num1>num3&&num2%2==1&&(num1-num3)%4==1){
        taxi = num4 + num3 + num2/2 + (num1-num3)/4 + 1;
    } else if(num1>num3&&num2%2==1&&(num1-num3)%4==2){
        taxi = num4 + num3 + num2/2 + (num1-num3)/4 + 1;
    } else if(num1>num3&&num2%2==1&&(num1-num3)%4==3){
        taxi = num4 + num3 + num2/2 + (num1-num3)/4 + 2;
    } else if(num3==num1&&num2%2==1){
        taxi = num4 + num3 + num2/2 + 1;
    } else if(num3==num1&&num2%2==0){
        taxi = num4 + num3 + num2/2;
    }
    
    cout << taxi;
}