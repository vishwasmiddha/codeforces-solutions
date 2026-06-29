#include <iostream>
#include <string>
#include <vector>
//#include <algorithm.h>
using namespace std;
#include <bits/stdc++.h> 
 
int maxv(int a, int b, int c, int d){
    int n1 = a>b?a:b;
    int n2 = c>d?c:d;
    return n1>n2?n1:n2;
}
 
int maxv(int a, int b, int c){
    int n1 = a>b?a:b;
    return n1>c?n1:c;
}
 
int maxv(int a, int b){
    return a>b?a:b;
}
 
int low1;
int low2;
 
bool lowest(vector<vector<int>>& arr, int a, int b){
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(arr[i][j]>maxv(arr[i+1][j],arr[i-1][j],arr[i][j+1],arr[i][j-1])){
                low1 = i;
                low2 = j;
                return true;
                break;
            }
        }
    }
    return false;
}
    
void reduce(std::vector<std::vector<int>>& arr){
    arr[low1][low2]=maxv(arr[low1+1][low2],arr[low1-1][low2],arr[low1][low2+1],arr[low1][low2-1]);
}
 
void printv(vector<vector<int>> arr,int a, int b){
    //cout << "ROWS: " << a << " COLUMNS: " << b << " 
";
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            cout << arr[i][j] << " ";
        }
        cout << "
";
    }
}
 
int main(){
    int loops;
    int n;
    int m;
    int some;
 
    cin >> loops;
    for(int a = 0;a<loops;a++){
        cin >> n >> m;
        vector<vector<int>> arra(n+2,std::vector<int>(m+2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> some;
                arra[i][j] = some;
            }
        }
        while(lowest(arra,n,m)){
        //printv(arra,n,m);
            reduce(arra);
        }
        printv(arra,n,m);
    }
}