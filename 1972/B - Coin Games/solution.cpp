#include <iostream>
#include <string>
#include <bitset>
//#include <algorithm.h>
using namespace std;
#include <bits/stdc++.h> 
 
int main(){
    int loops;
    int n;
    int u=0;
    string game;
    cin >> loops;
    for(int i=0;i<loops;i++){
        cin >> n;
        cin >> game;
        //cout << game << endl;
        for(int j=0;j<n;j++){
            if(game[j]=='U'){
                u++;
            }
        }
        if(u%2==0){
            //cout << u << endl;
            cout << "NO" << "
";
        } else {
            //cout << u << endl;
            cout << "YES" << "
";
        }
        u = 0;
        
    }
}